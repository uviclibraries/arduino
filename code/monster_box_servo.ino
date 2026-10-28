/*
  Monster box 1 - flashing RGB LEDs + YX5300 MP3 + servo prop
  Everything is non-blocking (millis timers), so lights, music and servo run at the same time.

  Parts: photoresistor, 1k resistors, 2 RGB LEDs, YX5300 MP3 module,
         servo (e.g. SG90), push button, PIR (HC-SR501), ultrasonic (HC-SR04)

  PIN MAP (unchanged pins first)
    LED 1  R/G/B ........ 11 / 10 / 9
    LED 2  R/G/B ........ 6 / 5 / 4
    YX5300 RX/TX ........ 2 (Arduino RX <- YX5300 TX) / 3 (Arduino TX -> YX5300 RX)
    Light sensor ........ A0
    Indicator LEDs ...... 13, 12
    --- new ---
    Servo signal ........ 7
    Push button ......... 8   (other leg to GND, internal pull-up used)
    PIR OUT ............. A1
    HC-SR04 TRIG ........ A2
    HC-SR04 ECHO ........ A3
*/

#include <SoftwareSerial.h>
#include <Servo.h>                 // Servo header file is needed to control the servo motor.

Servo servo1;                      // Create servo object to allow us to control the servo motor.

// ---------- RGB LED 1 ----------
const int redPin   = 11;
const int greenPin = 10;
const int bluePin  = 9;

// ---------- RGB LED 2 ----------
const int redPin2   = 6;
const int greenPin2 = 5;
const int bluePin2  = 4;

// Uncomment if using Common Anode LEDs
//#define COMMON_ANODE

// ---------- Other pins / light sensor ----------
const int ledPin1 = 13;
const int ledPin2 = 12;
const int sensorPin = A0;
const int sensorThreshold = 200;
int sensorValue;

// ---------- Servo / trigger pins ----------
const int servoPin  = 7;
const int buttonPin = 8;
const int pirPin    = A1;
const int trigPin   = A2;
const int echoPin   = A3;

// ---------- Choose which triggers are connected ----------
// Set to false for any part you have NOT wired (a floating input causes false triggers)
const bool USE_BUTTON     = true;
const bool USE_PIR        = true;
const bool USE_ULTRASONIC = true;

// ---------- Servo settings ----------
const int servoClosedAngle = 0;                  // resting position (lid closed)
const int servoOpenAngle   = 90;                 // moved position (lid open)
const unsigned long servoStepInterval = 15;      // ms per degree (bigger = slower, smoother)
const unsigned long servoHoldTime     = 3000;    // ms the prop stays open
const unsigned long servoCooldown     = 1000;    // ms before it can trigger again
const bool detachWhenIdle = true;                // stops servo buzzing/jitter and saves power
const bool servoWithLightShow = false;           // true = servo also moves when the light show starts

// ---------- Trigger settings ----------
const int distanceTriggerCm = 30;                // ultrasonic: trigger when something is closer than this
const unsigned long pirWarmupMs = 30000;         // PIR needs ~30-60 s to settle after power-up (set 0 to test)

enum ServoState { SERVO_IDLE, SERVO_OPENING, SERVO_HOLDING, SERVO_CLOSING, SERVO_COOLDOWN };
ServoState servoState = SERVO_IDLE;
int servoAngle = servoClosedAngle;
unsigned long servoTimer = 0;
bool servoAttached = false;

// ---------- YX5300 MP3 ----------
#define ARDUINO_RX 2   // Connect to TX of YX5300
#define ARDUINO_TX 3   // Connect to RX of YX5300
SoftwareSerial mp3(ARDUINO_RX, ARDUINO_TX);

uint8_t playFirst[]    = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x01, 0xEF};
uint8_t playSecond[]   = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x02, 0xEF};
uint8_t volumSet10[]   = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x0A, 0xEF};
uint8_t volumSet15[]   = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x0F, 0xEF};
uint8_t volumSet30[]   = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x1E, 0xEF};  // 30 = YX5300 maximum
uint8_t pauseCmd[]     = {0x7E, 0xFF, 0x06, 0x0E, 0x00, 0x00, 0x00, 0xEF};
uint8_t resumePlay[]   = {0x7E, 0xFF, 0x06, 0x0D, 0x00, 0x00, 0x00, 0xEF};
uint8_t stopPlay[]     = {0x7E, 0xFF, 0x06, 0x16, 0x00, 0x00, 0x00, 0xEF};

bool showActive = false;
bool volumePending = false;
uint8_t *pendingVolume = volumSet30;
size_t pendingVolumeSize = sizeof(volumSet30);
unsigned long playStartTime = 0;
const unsigned long volumeDelay = 500;

// ---------- Flashing colors ----------
const byte colors[][3] = {
  {255, 0, 0},     // red
  {0, 255, 0},     // green
  {0, 0, 255},     // blue
  {255, 255, 0},   // yellow
  {128, 0, 128},   // purple
  {0, 255, 255}    // aqua
};
const int numColors = sizeof(colors) / sizeof(colors[0]);
const unsigned long flashInterval = 200;
unsigned long lastFlash = 0;
int colorStep = 0;

// =====================================================
//                       MP3
// =====================================================
void mp3initial(void) {
  if (mp3.available()) {
    Serial.println("Response: ");
  } else {
    Serial.println(" there is something wrong in mp3.read()");
    delay(1000);
    Serial.println("mp3.read: ");
    Serial.println(mp3.read());
    Serial.println("mp3.available: ");
    Serial.println(mp3.available());
  }
}

// playflag: 0 = pause, 1 = song 1 (vol 30), 2 = song 2 (vol 15),
//           3 = song 2 (vol 10), 4 = resume, anything else = stop
void playControl(uint8_t playflag) {
  switch (playflag) {
    case 0:
      mp3.write(pauseCmd, sizeof(pauseCmd));
      Serial.println("Pause playing");
      break;
    case 1:
      Serial.println("Play first song...");
      mp3.write(playFirst, sizeof(playFirst));
      pendingVolume = volumSet30;
      pendingVolumeSize = sizeof(volumSet30);
      volumePending = true;
      playStartTime = millis();
      break;
    case 2:
      Serial.println("Play second song, volume 15...");
      mp3.write(playSecond, sizeof(playSecond));
      pendingVolume = volumSet15;
      pendingVolumeSize = sizeof(volumSet15);
      volumePending = true;
      playStartTime = millis();
      break;
    case 3:
      Serial.println("Play second song, volume 10...");
      mp3.write(playSecond, sizeof(playSecond));
      pendingVolume = volumSet10;
      pendingVolumeSize = sizeof(volumSet10);
      volumePending = true;
      playStartTime = millis();
      break;
    case 4:
      mp3.write(resumePlay, sizeof(resumePlay));
      break;
    default:
      mp3.write(stopPlay, sizeof(stopPlay));
      Serial.println("Stop playing");
      break;
  }
}

void updateMp3() {
  if (volumePending && millis() - playStartTime >= volumeDelay) {
    mp3.write(pendingVolume, pendingVolumeSize);
    volumePending = false;
  }
}

// =====================================================
//                       LEDs
// =====================================================
// NOTE: Servo.h uses Timer1, which disables PWM on pins 9 and 10.
// All six colors used here are full on/off anyway, so every LED channel
// uses digitalWrite (value >= 128 = on). The wiring does not change.
void setColor(int led, int red, int green, int blue) {
  bool r = red >= 128, g = green >= 128, b = blue >= 128;
#ifdef COMMON_ANODE
  r = !r; g = !g; b = !b;
#endif
  if (led == 1) {
    digitalWrite(redPin, r);
    digitalWrite(greenPin, g);
    digitalWrite(bluePin, b);
  } else if (led == 2) {
    digitalWrite(redPin2, r);
    digitalWrite(greenPin2, g);
    digitalWrite(bluePin2, b);
  }
}

void ledoff(int led) {
  setColor(led, 0, 0, 0);
}

// The two LEDs are 3 colors apart so they always show different colors
void updateFlashing() {
  unsigned long now = millis();
  if (now - lastFlash >= flashInterval) {
    lastFlash = now;
    int c1 = colorStep % numColors;
    int c2 = (colorStep + 3) % numColors;
    setColor(1, colors[c1][0], colors[c1][1], colors[c1][2]);
    setColor(2, colors[c2][0], colors[c2][1], colors[c2][2]);
    colorStep++;
  }
}

// =====================================================
//                       SERVO
// =====================================================
void servoEnable() {
  if (!servoAttached) {
    servo1.attach(servoPin);
    servo1.write(servoAngle);          // hold the last known angle right away
    servoAttached = true;
  }
}

void servoRelease() {
  if (detachWhenIdle && servoAttached) {
    servo1.detach();
    servoAttached = false;
  }
}

// Move one degree toward target; returns true when target is reached
bool stepToward(int target) {
  if (servoAngle == target) return true;
  servoAngle += (target > servoAngle) ? 1 : -1;
  servo1.write(servoAngle);
  return servoAngle == target;
}

// Called whenever a trigger is active
void requestServo() {
  if (servoState == SERVO_IDLE) {
    servoEnable();
    servoState = SERVO_OPENING;
    servoTimer = millis();
    Serial.println("Servo: opening");
  } else if (servoState == SERVO_HOLDING) {
    servoTimer = millis();             // still triggered: keep the prop open longer
  }
}

void updateServo() {
  unsigned long now = millis();
  switch (servoState) {
    case SERVO_IDLE:
      break;
    case SERVO_OPENING:
      if (now - servoTimer >= servoStepInterval) {
        servoTimer = now;
        if (stepToward(servoOpenAngle)) servoState = SERVO_HOLDING;
      }
      break;
    case SERVO_HOLDING:
      if (now - servoTimer >= servoHoldTime) {
        servoState = SERVO_CLOSING;
        servoTimer = now;
        Serial.println("Servo: closing");
      }
      break;
    case SERVO_CLOSING:
      if (now - servoTimer >= servoStepInterval) {
        servoTimer = now;
        if (stepToward(servoClosedAngle)) {
          servoRelease();
          servoState = SERVO_COOLDOWN;
        }
      }
      break;
    case SERVO_COOLDOWN:
      if (now - servoTimer >= servoCooldown) servoState = SERVO_IDLE;
      break;
  }
}

// =====================================================
//                    TRIGGER INPUTS
// =====================================================
// Push button: true once per press (debounced, active LOW)
bool buttonTriggered() {
  static bool lastReading = HIGH;
  static bool stableState = HIGH;
  static unsigned long lastChange = 0;
  bool reading = digitalRead(buttonPin);
  if (reading != lastReading) {
    lastChange = millis();
    lastReading = reading;
  }
  if (millis() - lastChange > 30 && reading != stableState) {
    stableState = reading;
    if (stableState == LOW) return true;
  }
  return false;
}

// PIR: HIGH = motion (ignored during warm-up)
bool pirTriggered() {
  return millis() > pirWarmupMs && digitalRead(pirPin) == HIGH;
}

// HC-SR04: measured every 100 ms; true while something is closer than distanceTriggerCm
bool ultrasonicTriggered() {
  static unsigned long lastPing = 0;
  static bool lastResult = false;
  if (millis() - lastPing >= 100) {
    lastPing = millis();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    unsigned long duration = pulseIn(echoPin, HIGH, 12000UL);   // 12 ms timeout (~2 m)
    float cm = duration * 0.0343 / 2.0;
    lastResult = (duration > 0 && cm > 2.0 && cm < distanceTriggerCm);
  }
  return lastResult;
}

void checkServoTriggers() {
  bool triggered = false;
  if (USE_BUTTON && buttonTriggered()) triggered = true;
  if (USE_PIR && pirTriggered()) triggered = true;
  if (USE_ULTRASONIC && ultrasonicTriggered()) triggered = true;
  if (triggered) requestServo();
}

// =====================================================
//                    MAIN LOGIC
// =====================================================
void lightsensing() {
  sensorValue = analogRead(sensorPin);

  // Print twice a second only (printing every loop slows the sketch down)
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 500) {
    lastPrint = millis();
    Serial.print("Light sensor Value is:");
    Serial.println(sensorValue);
  }

  // Same logic and direction as in your attached code:
  // below threshold = everything off, otherwise light show + music
  if (sensorValue < sensorThreshold) {
    if (showActive) {
      showActive = false;
      ledoff(1);
      ledoff(2);
      playControl(99);                   // stop music
    }
  } else {
    if (!showActive) {
      showActive = true;
      colorStep = 0;
      lastFlash = 0;
      playControl(1);                    // start music once
      if (servoWithLightShow) requestServo();
    }
    updateFlashing();
  }
}

void setup() {
  Serial.begin(9600);
  mp3.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  ledoff(1);
  ledoff(2);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Put the prop in its closed position at start-up
  servoEnable();
  delay(600);
  servoRelease();

  delay(500);
  mp3initial();

  // Incoming YX5300 replies are not used. Ignoring them stops SoftwareSerial from
  // disabling interrupts mid-byte, which would make the servo twitch. Sending still works.
  mp3.stopListening();
}

void loop() {
  lightsensing();
  updateMp3();
  checkServoTriggers();
  updateServo();
}
