/*
  Monster box 1

  This sketch is written to accompany Monster box project for Halloween theme workshop 

  Parts required:
  - photoresistor
  - 1 kilohm resistors
  - 2 Leds
  - piezo

  
*/

//For RGB Led
// Updated to standard Arduino Uno PWM pins (3, 5, 6)
int redPin = 10;//With a 1k resistor, connted to the second longest lead of the LED, besides the longest
int greenPin = 9;//With a 1k resistor,connted to third longest lead of the LED, between the longest and shortest
int bluePin = 8;//With a 1k resistor,connted to shortest lead of the LED,
//For a common Cathod LED, connect the longest lead is the Cathod LED, connect to a GND of the Arduino board.
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE


int redPin2 = 6;//With a 1k resistor, connted to the second longest lead of the LED, besides the longest
int greenPin2 = 5;//With a 1k resistor,connted to third longest lead of the LED, between the longest and shortest
int bluePin2 = 4;//With a 1k resistor,connted to shortest lead of the LED,
//For a common Cathod LED, connect the longest lead is the Cathod LED, connect to a GND of the Arduino board.
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE


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


//mp3 play control 
void playControl(uint8_t vol,uint8_t playflag){

    //The volume will change will the speaker output is set at a certain level, otherwise, you could not figure out the changes
    /*
  switch(vol){
  case 10:
  Serial.println("Set volum 10...");
  break;
  mp3.write(volumSet10, sizeof(volumSet10)); // Set volume to 10
  delay(500); // play for 0.5 seconds
  break;
  case 15:
  Serial.println("Set volum 15...");
  break;
  mp3.write(volumSet15, sizeof(volumSet15)); // Set volume to 10
  delay(500); // play for 0.5 seconds
  break;
  case 30:
  Serial.println("Set volum 30...");
  mp3.write(volumSet30, sizeof(volumSet30)); // Send play command
 
  delay(500); 
  break;
  case 60:
  Serial.println("Set volum 60...");
  mp3.write(volumSet60, sizeof(volumSet60)); // Set volume to 10
   //volumeup(10);//increase volume by 10
  delay(500); // play for 0.5 seconds
  break;
  default:
  Serial.println("do nothing");
  break;
  }
*/

// The volume settings only effective after writing the playing songs command
  switch (playflag){
  case 0:
      mp3.write(pause, sizeof(pause)); // pause
      Serial.println("pause playing for 1 second...");
      delay(1000); // Give the module time to repsonse and pause for 1 seconds
  break;
  case 1:
      //during playing, other commands may disrupte the playing
      Serial.println("Play first song...");
      mp3.write(playFirst, sizeof(playFirst)); // Send play command
      delay(500); // play for 0.5 seconds
      mp3.write(volumSet60, sizeof(volumSet60)); // Set volume to 60
     
      delay(10000); // Play the songs for 10 seconds
      Serial.println("The first song is playing..."); 
  break;
  
  case 2:
      mp3.write(playSecond, sizeof(playSecond)); // pause
      delay(500); // play for 0.5 seconds
      Serial.println("Playing second song for 10 seconds...");
      mp3.write(volumSet15, sizeof(volumSet15)); // Set volume to 15
      delay(500); // play for 0.5 seconds
      delay(10000); // Give the module time to repsonse and pause for 1 seconds
      Serial.println("The second song is playing..."); 
  break;

  case 3:
      mp3.write(playSecond, sizeof(playSecond)); // pause
      Serial.println("Playing second song for 10 seconds...");
      mp3.write(volumSet10, sizeof(volumSet10)); // Set volume to 10
      delay(500); // play for 0.5 seconds
      delay(10000); // Give the module time to repsonse and pause for 1 seconds
      Serial.println("The second song is playing..."); 
  break;
  default:
      mp3.write(stopPlay, sizeof(stopPlay)); // stop
      Serial.println("Stop playing for 1 second...");
      delay(1000); // Give the module time to repsonse and pause for 1 seconds
  break;
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

  mp3initial();
 
  //for RGB Led
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);  
  delay(500); // Give the module time to initialize
}
void loop() {

   lightsensing();
  
}
