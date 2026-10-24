/*
  Monster box 1 - flashing RGB LEDs + YX5300 MP3, non-blocking
*/

#include <SoftwareSerial.h>

// ---------- RGB LED 1 (all PWM) ----------
const int redPin   = 11;
const int greenPin = 10;
const int bluePin  = 9;

// ---------- RGB LED 2 ----------
const int redPin2   = 6;   // PWM
const int greenPin2 = 5;   // PWM
const int bluePin2  = 4;   // not PWM: analogWrite gives on (>=128) / off (<128)

// Uncomment if using Common Anode LEDs
//#define COMMON_ANODE

// ---------- Other pins / sensor ----------
const int ledPin1 = 13;
const int ledPin2 = 12;
const int sensorPin = A0;
const int sensorThreshold = 200;   // larger value = darker
int sensorValue;

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

// Non-blocking playback state
bool showActive = false;
bool volumePending = false;
uint8_t *pendingVolume = volumSet30;
size_t pendingVolumeSize = sizeof(volumSet30);
unsigned long playStartTime = 0;
const unsigned long volumeDelay = 500;

// ---------- Flashing colors (PWM values) ----------
const byte colors[][3] = {
  {255, 0, 0},     // red
  {0, 255, 0},     // green
  {0, 0, 255},     // blue
  {255, 255, 0},   // yellow
  {128, 0, 128},   // purple (128 so LED 2's on/off blue pin switches on)
  {0, 255, 255}    // aqua
};
const int numColors = sizeof(colors) / sizeof(colors[0]);
const unsigned long flashInterval = 200;
unsigned long lastFlash = 0;
int colorStep = 0;

// ---------- MP3 ----------
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

// ---------- LEDs ----------
void setColor(int led, int red, int green, int blue) {
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  if (led == 1) {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  } else if (led == 2) {
    analogWrite(redPin2, red);
    analogWrite(greenPin2, green);
    analogWrite(bluePin2, blue);   // on/off only on pin 4
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

// ---------- Main logic ----------
void lightsensing() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Light sensor Value is:");
  Serial.println(sensorValue);

  if (sensorValue < sensorThreshold) {   // bright: everything off
    if (showActive) {
      showActive = false;
      ledoff(1);
      ledoff(2);
      playControl(99);                   // stop music
    }
  } else {                               // trigger condition as in your original code
    if (!showActive) {
      showActive = true;
      colorStep = 0;
      lastFlash = 0;
      playControl(1);                    // start music once
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

  delay(500);
  mp3initial();
}

void loop() {
  lightsensing();
  updateMp3();
}
