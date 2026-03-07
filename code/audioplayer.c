
/* This program uses ultrasonic sensor HC-SR04 to measurement the distance and mp3 player to play music
 * When the object closed to a distance for example 20 cm, a piece of music will play until the end of the music
 *
 * 
 *
 * by GLL
 */
 //pin out definition for HC-SR04
const int trigPin = 9;
const int echoPin = 10;
const int greenLedPin = 11;    // the number of the Green LED 
const int redLedPin = 12;    // the number of the Red LED 
//define for distance measurement
float duration, distance;


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


// the setup function runs once when you press reset or power the board
void measurement_initilize() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Serial.begin(9600);
}


float distance_measure(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
  delay(100);
}

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

void volumeup(uint8_t j){
  i=0;
  for(i;i<j;i++){
    mp3.write(volumUpOne, sizeof(volumUpOne)); // Send play command
    delay(500); // Give the module time to initialize
    Serial.println("Volum up one when playing songs...");
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
      mp3.write(volumSet60, sizeof(volumSet60)); // Set volume to 60
     
      delay(10000); // Play the songs for 10 seconds
      Serial.println("The first song is playing..."); 
  break;
  
  case 2:
      mp3.write(playSecond, sizeof(playSecond)); // pause
      Serial.println("Playing second song for 30 seconds...");
      mp3.write(volumSet15, sizeof(volumSet15)); // Set volume to 15
      delay(500); // play for 0.5 seconds
      delay(10000); // Give the module time to repsonse and pause for 1 seconds
      Serial.println("The second song is playing..."); 
  break;

  case 3:
      mp3.write(playSecond, sizeof(playSecond)); // pause
      Serial.println("Playing second song for 30 seconds...");
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
  measurement_initilize();
  mp3initial();
  Serial.begin(9600);
  mp3.begin(9600);
  delay(500); // Give the module time to initialize
 
}


// the loop function runs over and over again forever
void loop() {
  float distanceMeasured=0;
  delay(100);
  distanceMeasured=distance_measure();
  Serial.print("Distance(cm): ");
  Serial.println(distanceMeasured);
  if (distanceMeasured>50){
    digitalWrite(greenLedPin, LOW);   // turn the LED OFF (LOW is the voltage level)
    digitalWrite(redLedPin, LOW);    // turn the LED off by making the voltage LOW
    playControl(0,0);// not to play mp3 if distance> 50cm
  }
  else if(distanceMeasured>30){
    digitalWrite(greenLedPin, LOW);   // turn the LED OFF (LOW is the voltage level)
    digitalWrite(redLedPin, HIGH);    // turn the LED ON by making the voltage HIGH
     playControl(60,1);// play mp3 with volume 60 if distance < 50cm and >20cm
  }

 else if(distanceMeasured>20){
    digitalWrite(greenLedPin, HIGH);   // turn the LED ON (HIGH is the voltage level)
    digitalWrite(redLedPin, LOW);    // turn the LED LOW by making the voltage LOW
    playControl(30,2);// play mp3 with volume 30 if distance < 30cm and >20cm
  }
  else{
    digitalWrite(greenLedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(redLedPin, HIGH);    // turn the LED on by making the voltage HIGH
    playControl(10,3);// play second mp3 file with volume 10 if distance < 20cm
  }

}










