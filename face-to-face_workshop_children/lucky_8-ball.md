---
layout: default
title: Lucky 8-Ball
nav_order: 5
parent: Face-to-Face Workshop Activities
---

# Lucky 8-Ball

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
    <img src="..\images\in-person_workshops\lucky_8-ball\10k-ohm_res.png" alt="10 kilo ohm resistor" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\220-ohm_res.png" alt="220 ohm resistor" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\tilt_switch.png" alt="tilt switch" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\potentiometer.png" alt="potentiometer" style="float:right;width:120px;">
    - 1 LCD Screen (see below)
    - 1 Tilt Switch (4 prongs)
    - 1 10k-ohm Resistor with the following striping in order: brown, black, orange, gold
    - 1 220-ohm Resistor with the following striping in order: red, red, brown, gold
    - 1 Potentiometer
    - 1 Long Red Wire
    - 1 Long Black Wire
    - See Below for the remaining wires and their placement

2.  Connect the black wire to the **GND** pin on the Arduino and then the “**-**” pin on the breadboard.

3.  Connect the red wire to the **5V** pin on the Arduino and then the “**+**” pin on the breadboard.

4.  Connect all the other wires as can be seen in the diagram below.

    <img src="..\images\in-person_workshops\lucky_8-ball\breadboard_schematic.png" alt="breadboard" style="width:480px;">

    Note: you can check out a [simulated version](https://www.tinkercad.com/things/iA5jDh1yDiz){:target="_blank"} of this Arduino project

5.  Using the provided USB cable plug your Arduino into your computer.

6.  Launch the arduino software.

7.  Go to the top menu of the Arduino Program and select: **File -> Examples -> 10.StarterKit_BasicKit -> p11_CrystalBall**

8.  Upload the **Crystal Ball** code to your Arduino by pressing the **Upload** button.

    <img src="..\images\in-person_workshops\lucky_8-ball\upload.png" alt="upload" style="width:480px;">

9.  Twist the potentiometer until you see words appear on the screen. Once the code is uploaded and running, you trigger your Lucky 8-Ball by moving its base gently up and down to trigger the tilt sensor. The tilt sensor and the potentiometer can sometimes pop out, so you might have to keep a finger on the sensor as you shake it!

10.  You should probably customize the responses of your lucky 8-Ball by going into the Arduino software and scrolling down to almost the bottom of the code for the project and look for, **lcd.print("Yes");**, and **lcd.print("Most likely");**. Go ahead and change any or all of the 8 different responses that your Lucky 8-Ball gives out (just remember that your responses still have to fit on the LCD screen). Upload your revised code, and you’re off to the races. Enjoy!

[NEXT PROJECT: Electronic Die](electronic_die.html){: .btn .btn-blue }
