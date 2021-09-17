---
layout: default
title: Light Theremin
nav_order: 7
parent: Face-to-Face Workshop Activities
---

# Light Theremin

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
    - 1 Piezo (this is basically a small speaker)
    - 1 Photoresistor (this is a light sensor)
    - 1 10k-ohm resistor with the following striping in order: brown, black, orange, gold
    - 1 Long Red Wire
    - 1 Long Black Wire
    - 2 Short Wires
    - 1 Medium Wire
    - 1 Long Wire
    <br><img src="..\images\in-person_workshops\light_theremin\piezo.png" alt="piezo" style="width:120px;">
    <img src="..\images\in-person_workshops\light_theremin\photores.png" alt="photoresistor" style="width:120px;">

2.  Connect as shown in this diagram (note: the Piezo legs are closer together than displayed here -- just make sure the two adjacent wires in Column A are in the same row as the Piezo legs):

    <img src="..\images\in-person_workshops\light_theremin\breadboard_schematic.png" alt="breadboard" style="width:480px;">

    Note: you can check out a [simulated version](https://goo.gl/Tq5TpD){:target="_blank"} of this Arduino project

3.  Using the provided USB cable plug your Arduino into your computer.

4.  Launch the arduino software.

5.  Go to the top menu: “**File**” -> “**Examples**” -> “**10.StarterKit_BasicKit**” -> “**p06_LightTheremin**”

    <img src="..\images\in-person_workshops\light_theremin\menus.png" alt="menu navigation" style="width:480px;">

6.  Upload the “**Light Theremin**” code to your Arduino by pressing the “**Upload**” button.

    <img src="..\images\in-person_workshops\light_theremin\upload.png" alt="upload" style="width:480px;">

7.  Once the code is uploaded and running, there is a 5 second initialization phase where the ambient light level is recorded. After that, move your finger around the photoresistor to make some crazy Theremin sounds!  Enjoy!

[NEXT STEP: Earn a Workshop Badge](../informal-credentials.html){: .btn .btn-blue }
