---
layout: default
title: Covid Sensor
nav_order: 9
parent: Face-to-Face Workshop Activities
---

# Covid-sensor

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software) for either Windows or Mac, and then install the software on your computer.

    Materials needed:
    <img src="..\images\in-person_workshops\hello_world\led.png" alt="led" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\hello_world\res.png" alt="led" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="led" style="float:right;width:120px;">
    - 1 Red LED Light and 1 green LED light
    - 1 Ultrasonic Sensor
    - 2 1k-ohm Resistors
    - Some Medium Wires
    - Some Short Wires
    - Arduino UNO

    Attach as displayed in this diagram (note that the squiggly lines indicate the longer legs of the LEDs):

    <img src="..\images\in-person_workshops\covid_sensor\distancemeasurement.png" alt="distancemeasurement" style="width:480px;">

    Note: you can check out a [simulated version](https://www.tinkercad.com/things/lVIOuA9hAri/editel?returnTo=%2Fcircuits&sharecode=ePzhFElFQH2dRSZXLS5rEwq7nOPiU28CIo3uRnXhjYQ){:target="_blank"} of this Arduino Project

2.  Using the provided USB cable plug your Arduino into your computer.

3.  Launch the Arduino software.

4.  Go to the top menu and select: **Files -> New 

 paste the codes from link below:
 https://drive.google.com/file/d/1MjVNvSdijq45YQKWWXrXKRewwlCtaCjq/view?usp=sharing

 and select the arduino uno as in the boards management menue:
 
 <img src="..\images\in-person_workshops\covid_sensor\distance_boardselect.png" alt="upload" style="width:600px;">

5.  Upload the codes to your Arduino by pressing the **Upload** button.

    <img src="..\images\in-person_workshops\covid_sensor\distance_upload.png" alt="upload" style="width:600px;">

6.  Open the serial mornitor window from the Tools menu, you will keep on seeing the distance in cm unit output from the serial mornitor window. Put your hand or other objects closer to the ultrasonic sensor for less than 20 cm, you will see the red LED on and green light will be off; move the objects away, you will see the red light off and green light on. Change the threshold value in the codes to see the what will changes. Enjoy!

Object is 20 cm away:

<img src="..\images\in-person_workshops\covid_sensor\greenlight.jpg" alt="greenlight" style="width:600px;">
     
Object is in 20 cm :

<img src="..\images\in-person_workshops\covid_sensor\redlight.jpg" alt="redlight" style="width:600px;">

