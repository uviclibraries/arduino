/*
  Monster box 1

  This sketch is written to accompany Monster box project for Halloween theme workshop 

  Parts required:
  - photoresistor
  - 1 kilohm resistors
  - 2 Leds
  - piezo

  
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

// map the sensor values to a wide range of pitches
int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

void setup() {
  Serial.begin(9600);
  // Make the LED pin an output and turn it on
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  //pinMode(pirPin,INPUT);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
}

void lightsensing(){

  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);
  Serial.print("Light sensor Value is:");
  Serial.println(sensorValue);
  //delay(3000);
  //The larger the sensorValue, the darker of the environment
  if (sensorValue>sensorThreshold){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW); 
    }
  else
  {
    
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);   
     // play the tone for 20 ms on pin 8
     tone(8, pitch, 20);
    }
}



void loop() {

   lightsensing();
  
}
