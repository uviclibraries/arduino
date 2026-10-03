/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

const int trigPin = 9;
const int echoPin = 10;
const int greenLedPin = 11;    // the number of the Green LED 
const int redLedPin = 12;    // the number of the Red LED 

float duration, distance;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
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
// the loop function runs over and over again forever
void loop() {
  float distanceMeasured=0;
  delay(100);
  distanceMeasured=distance_measure();
  Serial.print("Distance(cm): ");
  Serial.println(distanceMeasured);
  if (distanceMeasured>20){//if measure distance larger than 20cm
    digitalWrite(greenLedPin, HIGH);   // turn the Green LED on (HIGH is the voltage level)
    digitalWrite(redLedPin, LOW);    // turn the Red LED off by making the voltage LOW
    
  }
  else{ //if measure distance smaller than 20cm
    digitalWrite(greenLedPin, LOW);   // turn the Green LED off (LOW is the voltage level)
    digitalWrite(redLedPin, HIGH);    // turn the red LED on by making the voltage HIGH
  }

}
