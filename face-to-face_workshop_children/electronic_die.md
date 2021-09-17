---
layout: default
title: Electronic Die
nav_order: 6
parent: Face-to-Face Workshop Activities
---
<img src="..\images\arduino-icon.png" alt="arduino icon" style="float:right;width:180px;">

# Electronic Die

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
    - 4 LED Lights - 1 Blue, 1 Yellow, 1 Red, 1 Green
    - 1 560-ohm Resistor with the following striping in order: green, blue, brown, gold
    - 4 Long Orange Wires
    - 1 Long Black Wire
    - 1 Short Yellow Wire
    - 3 Short Purple Wires
    <img src="..\images\in-person_workshops\electronic_die\LED.png" alt="led" style="width:90px;">
    <img src="..\images\in-person_workshops\electronic_die\560-ohm_res.png" alt="560 ohm resistor" style="width:90px;">

2.  Connect the black wire to the “**GND**” pin on the Arduino and then the “**-**” pin on the breadboard.

    <img src="..\images\in-person_workshops\electronic_die\breadboard_schematic.png" alt="breadboard" style="width:480px;">

    Note: you can check out a [simulated version](https://goo.gl/NYzKt4){:target="_blank"} of this Arduino project

3.  Connect the gold end of the 560-ohm resistor to the ground or “**-**” side of the breadboard, and then to the “**B3**” pin in the breadboard. Connect the pins “**E3**” and “**F3**” using your short yellow wire.

4.  For this circuit you will be connecting 4 LED lights in series. The order of the colours are arbitrary.

5.  Place your first LED with the longer leg in the “**I3**” pin of the bread board, and the shorter leg into the “**I4**” pin.

6.  Connect an orange wire from “**I4**” of the first LED to “**TX -> 1**” on the arduino.

7.  Connect the remaining LED lights in series using the short purple wires, connecting each LED’s shorter leg to the one beside it.

8.  For each of the remaining 3 LEDs, use a long orange wire to connect the long leg of the LED to one of the Arduino Digital pins numbered 1 to 4 (along the right hand side of the Arduino).

9.  Using the provided USB cable, plug your Arduino into your computer.

10.  Launch the arduino software.

11.  Go to the top menu and select: “**Files**” -> “**New**”

12.  Delete any content in script window and paste the code from the following document:

    [https://goo.gl/ZcRBf4](https://goo.gl/ZcRBf4){:target="_blank"}

13.  **TODO: RESOLVE THIS WORKSHOP WITH A CUTE LINE**

[NEXT PROJECT: Light Theremin](light_theremin.html){: .btn .btn-blue }
