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


//define for mp3 player
#include <SoftwareSerial.h>
//The RX/Tx for the on-hand YX5300 is different from others, RX in this model is Transmitter pin,3.4V, TX in this model is receiver pin 4.9V
//
//Only when YX5300 power on, mp3.available() outputs 9-8-7-6-5-4-3-2-1-0;:
//and mp3.read() for data buffer output non -1 as: 126 255 3F 0 0 2 FE BA EF

#define ARDUINO_RX 2 // Connect to RX of YX5300
#define ARDUINO_TX 3 // Connect to TX of YX5300

SoftwareSerial mp3(ARDUINO_RX, ARDUINO_TX);

// Command to play the first track in the first folder,0x01 is for the first file(track)
uint8_t playFirst[] = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x01, 0xEF};
// Command to play the first track in the first folder,0x02 is for the first file(track)
uint8_t playSecond[] = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x02, 0xEF};
uint8_t volumUpOne[] = {0x7E, 0xFF, 0x06, 0x04, 0x00, 0x00, 0x00, 0xEF};
uint8_t volumDownOne[] = {0x7E, 0xFF, 0x06, 0x04, 0x00, 0x00, 0x00, 0xEF};
uint8_t volumSet10[] = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x0A, 0xEF};//0A is 10 in hex
uint8_t volumSet15[] = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x0F, 0xEF};//0F is 15 in hex
uint8_t volumSet30[] = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x1E, 0xEF};//0X1E is 30 in hex
uint8_t volumSet60[] = {0x7E, 0xFF, 0x06, 0x06, 0x00, 0x00, 0x3C, 0xEF};//0X3C is 60 in hex
uint8_t pause[] = {0x7E, 0xFF, 0x06, 0x0E, 0x00, 0x00, 0x00, 0xEF};
uint8_t resumePlay[] = {0x7E, 0xFF, 0x06, 0x0D, 0x00, 0x00, 0x00, 0xEF};
uint8_t stopPlay[] = {0x7E, 0xFF, 0x06, 0x16, 0x00, 0x00, 0x00, 0xEF};
uint8_t i=0;

void mp3initial(void){
  // Only mp3 player power on and right after initializing, it is avaiable and read out 1, but mp3 is working
  if (mp3.available()) {
    Serial.println("Response: ");
  }
  else{
    Serial.println(" there is something wrong in mp3.read()");
    delay(1000); //Delay 1 second
    Serial.println("mp3.read: ");
    Serial.println(mp3.read());
    Serial.println("mp3.read in HEX: ");
    Serial.println(mp3.read(), HEX);
    Serial.println("mp3.availbale: ");
    Serial.println(mp3.available());
  }
}

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
