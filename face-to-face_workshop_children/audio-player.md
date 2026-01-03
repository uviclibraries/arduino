---
layout: default
title: Audio Player
nav_order: 8
parent: Face-to-Face Workshop Activities
---

# Audio-player

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
    <img src="..\images\in-person_workshops\lucky_8-ball\10k-ohm_res.png" alt="10 kilo ohm resistor" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\220-ohm_res.png" alt="220 ohm resistor" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\tilt_switch.png" alt="tilt switch" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\lucky_8-ball\potentiometer.png" alt="potentiometer" style="float:right;width:120px;">
    - 1 Arduino MKR Zero or MKR 1010 (see below)
    - HC-SR04 Ultrasonic sensor (see below)
    - 1 LM386 amplifier board (see below)
    - 1 speaker (see below)
    - 1 32GB SD card (see below)

    - See Below for the remaining wires and their placement

2.  Connect the black wire to the **GND** pin on the Arduino and then the “**-**” pin on the breadboard.

3.  Connect the red wire to the **5V** pin on the Arduino and then the “**+**” pin on the breadboard.

4.  Connect all the other wires as can be seen in the diagram below.

    <img src="..\images\in-person_workshops\lucky_8-ball\breadboard_schematic.png" alt="breadboard" style="width:480px;">

    Note: you can check out a [simulated version](https://www.tinkercad.com/things/iA5jDh1yDiz){:target="_blank"} of this Arduino project.
    


     Detailed explanation can be referred to the link: https://docs.arduino.cc/tutorials/generic/simple-audio-player/ 
    

6.  Launch the arduino IDE.

7.  Make sure that the SD card have correct audio file(test.wav) and then insert the SD card into the SD card slot. 
   
8.  Using the provided USB cable to connect your Arduino board to your computer.

9.  Install the libraries for the MKR board: Go the menu: tool-board manager-search MKR and install
   
10.  Install the software libraries: Tool-library-search 'Audiozero'

11.  Open the project with below path. Delete the codes for the file and replace with this file:  Go to the top menu of the Arduino Program and select Auduino MKR Zero. Open the serial port window. Press the arrow button and upload the codes to the board. Wait for a few seconds.

12.  From the serial minitor window, you will see the test.wav file has been open and it keeps on printing out the distance information. Put your hands or other object closer to the ultrsonic sensor (less then 20cm), you will hear the music from the speaker! Enjoy the music!



 
