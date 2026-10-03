/*
  Arduino Starter Kit example
  Project 6 - Light Theremin

  This sketch is written to accompany Project 6 in the Arduino Starter Kit

  Parts required:
  - photoresistor
  - 10 kilohm resistor
  - piezo

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin1 = 13;
const int ledPin2 = 12;
const int sensorThreshold=800;
const int pirPin=11;//has to use 3K pull down resistor

int pirValue = LOW;
int lastPirValue = LOW; // Keeps track of the previous state to stop the spamming loops


void setup() {
  Serial.begin(9600);
  // Make the LED pin an output and turn it on
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //pinMode(pirPin,INPUT);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  // calibrate for the first five seconds after program runs
   while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
   Serial.print("Light sensor Value is:");
   Serial.println(sensorValue);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  //PIT sensor need 30s to warm up and analyze ambient infrared level
  delay(25000);
  Serial.println("Sensor Active!");
}

void lightsensing(){

  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);
  Serial.print("Light sensor Value is:");
  Serial.println(sensorValue);
  delay(3000);
  //The larger the sensorValue, the darker of the environment
  if (sensorValue>sensorThreshold){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW); 
    }
  else
  {
    
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH); 
    }
}




void pirsensing(){
  pirValue = digitalRead(pirPin);
  
  // State Change Detection: Only run code when the sensor actually switches states
  if (pirValue != lastPirValue) {
    
    // CORRECTED LOGIC: HIGH (1) genuinely means motion is detected
    if (pirValue == HIGH) {
      Serial.println("--> REAL MOTION DETECTED (Signal is 1) <--");
      digitalWrite(ledPin1, HIGH); // Turn LED 1 ON
      digitalWrite(ledPin2, LOW);  // Turn LED 2 OFF
    } 
    // LOW (0) genuinely means the area is clear
    else {
      Serial.println("--> AREA CLEAR / NO MOTION (Signal is 0) <--");
      digitalWrite(ledPin1, LOW);  // Turn LED 1 OFF
      digitalWrite(ledPin2, HIGH); // Turn LED 2 ON
    }
    
    // Save the current state as the last state for the next check
    lastPirValue = pirValue; 
    
    // Microscopic stabilization delay for breadboard power line noise
    delay(50); 
  }
}



void loop() {
  
   //lightsensing();
   pirsensing();
  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // play the tone for 20 ms on pin 8
  //tone(8, pitch, 20);

  // wait for a moment
  //delay(1000);
}
