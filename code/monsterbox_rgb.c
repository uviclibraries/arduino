/*
Monster box workshop using. RGB LED
*/

// Updated to standard Arduino Uno PWM pins (3, 5, 6)
int redPin = 3;//With a 1k resistor, connted to the second longest lead of the LED, besides the longest
int greenPin = 5;//With a 1k resistor,connted to third longest lead of the LED, between the longest and shortest
int bluePin = 6;//With a 1k resistor,connted to shortest lead of the LED,
//For a common Cathod LED, connect the longest lead is the Cathod LED, connect to a GND of the Arduino board.
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(255, 0, 0);  // red
  
  delay(1000);
  
  setColor(0, 255, 0);  // green
  delay(1000);
  
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
  
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
