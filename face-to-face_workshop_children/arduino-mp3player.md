---
layout: default
title: Arduino MP3 Player
nav_order: 2
parent: Face-to-Face Workshop Activities
---

# Arduino MP3 Player

This page is for a Arduino audio player solution with Arduino UNO R3 + low-noise MP3 player. Another solution for audio play with Arduino MKR WiFi 1010 or MKR Zero can be found in audio-player.md

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
 
    - 1 Arduino UNO R3 (see below)
    
     <img src="..\images\in-person_workshops\mp3player\arduino_r3.png" alt="arduino_r3" style="float:right;width:320px;">


 - MP3 player with SD card shield slot and 3.5mm Jack audio connector (see below)
   
 - HC-SR04 Ultrasonic sensor (see below)

<img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="hc-sr04" style="float:right;width:320px;">

- YX5300 MP3 player board (see below)

<img src="..\images\in-person_workshops\mp3player\yx5300.png" alt="LM386" style="float:right;width:320px;">
    
- One active(embedded with amplifier) speaker (see below)
   
<img src="..\images\in-person_workshops\mp3player\sharkspeaker.png" alt="speaker" style="float:right;width:220px;">    
    
- One 32GB SD card with FAT file system and stored with some .wav or .mp3 audio files. The file name has to be in the
  format of file order+ three characters.wav or .mp3, for instance: 01tet.wav or 02ply.mp3. The files have to be stored
 in the top-level directory of the SD drive or folders with names of three-digital such as 001 or 002 etc.


2.   Make sure that the SD card have correct audio file, file name and folder name and then insert the SD card into the SD card slot. 

3.  Connect the black wire to the **GND** pin on the Arduino and then the “**-**” pin on the breadboard.

    Connect the red wire to the **5V** pin on the Arduino and then the “**+**” pin on the breadboard.
   
4.  Connect all the other wires and their placement as can be seen in the diagram below.  
For MKR zero:
     <img src="..\images\in-person_workshops\audio_player\audio_player3.png" alt="audio_player" style="float:right;width:1200px;">



***Please notice that the breadboard power has to be connected to 5V (from Arduino MKR board), otherwise, the mp3 player might not work properly) 

5.  Launch the arduino IDE. Use the provided USB cable to connect your Arduino board to your computer.

6.  Install the libraries for the Arduino UNO board: Go to the menu: Tools-boards manager-search with keyword 'UNO' and install "Arduino AVR boards"
  <img src="..\images\in-person_workshops\audio_player\mkrinstall.png" alt="mkrinstall" style="float:right;width:1200px;">
  Go to the menu of the IDE and select Tools- boards manager again to select, connect and communicate with the board Auduino UNO.
<img src="..\images\in-person_workshops\audio_player\boardmanager.png" alt="boardmanager" style="float:right;width:1200px;">
   
   
7.  Install the software libraries from the menu: Tools-libraries-search 'UNO'
     <img src="..\images\in-person_workshops\audio_player\audiozeroinstall.png" alt="audiozero" style="float:right;width:1200px;">

     
8. Select the com port for the board from the tools menu. Also open the serial port window from the tools menu.
    <img src="..\images\in-person_workshops\audio_player\selectcom.png" alt="boardmanager" style="float:right;width:1200px;">
    
9.  Open a new scratch: Delete all the lines of codes for the file, copy and paste to replace with this file:  https://github.com/uviclibraries/arduino/blob/audio-player/code/audioplayer.c

    Press the arrow button and upload the codes to the board. Wait for a few seconds.
 <img src="..\images\in-person_workshops\audio_player\filepath.png" alt="filepath" style="float:right;width:1200px;">
 
11.  From the serial monitor window, you will the serial monitor window keeps on printing out the system information.
    When there is no object within 50 mm in front of ultrasonic sensor, the audio player won't play and keep on outputting the distance information in the serial monitor window.
Put your hands or other objects closer to the ultrsonic sensor (less then 50cm), you will hear the music from the speaker! And the red LED or green LED will be on.
If your hands or other objects closer to the ultrsonic sensor (less then 20cm), you will hear another music from the speaker, both of the red LED and green LED will be on, and the
volume from the speakers also change! Have fun!


12.  If you want to discover more, you can go back to the code editor of Arduino IDE, modify the variables in the code, recompile,
 and upload your updated code to the Arduino board to see the results. For instance, change the distance threshold of starting playing
music from 50 mm to 80 mm to see whether it will actually happen.  Or you can change the music files, change the LEDs light,
change the volumes etc to have more fun from it!

 
