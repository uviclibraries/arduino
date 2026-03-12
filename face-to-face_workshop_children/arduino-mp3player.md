---
layout: default
title: Arduino MP3 Player
nav_order: 2
parent: Face-to-Face Workshop Activities
---

# Arduino MP3 Player

This page describes an Arduino audio player project using an Arduino UNO R3, a YX5300 MP3 player module, and an active speaker. Another audio play solution using the Arduino MKR WiFi 1010 or MKR Zero can be found in audio-player.md.

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software) for either Windows or Mac, and then install the software on your computer. Another alternative is to use the cloud IDE. Please refer to this link on how to use the cloud IDE for our workshop: https://github.com/uviclibraries/arduino/blob/audio-player/face-to-face_workshop_children/cloud_IDE.md

    Materials Needed:
 
- 1 Arduino UNO R3 (see below)
    
     <img src="..\images\in-person_workshops\mp3player\arduino_r3.png" alt="arduino_r3" style="float:right;width:320px;">


- MP3 player with SD card shield slot and 3.5mm Jack audio connector that is the YX5300 MP3 player board (see below)

   <img src="..\images\in-person_workshops\mp3player\yx5300.png" alt="arduino_r3" style="float:right;width:320px;">

   
- HC-SR04 Ultrasonic sensor (see below)

<img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="hc-sr04" style="float:right;width:320px;">
    
- One active(embedded with amplifier) speaker with audio cable connect to the YX5300 module (see below). The actual print put of the pin might be different(TX and RX are swapped), Just follow the connections for the pin position.
   
<img src="..\images\in-person_workshops\mp3player\sharkspeaker.png" alt="speaker" style="float:right;width:220px;">    
    
- One 32GB SD card with FAT file system and stored with some .wav or .mp3 audio files.

- The file name must follow this format:
two-digit file number + three characters + file extension, example: 01tet.wav or 02ply.mp3.

The files have to be stored in the top-level directory of the SD drive or folders with three-digit names, such as 001 or 002 etc.


2.   Make sure that the SD card have correct audio file, file name and folder name and then insert the SD card into the SD card slot. 

3.  Connect a black wire from the GND pin on the Arduino to the “-” (ground) rail on the breadboard.

    Connect a red wire from the **5V** pin on the Arduino to the “**+**”(power) rail on the breadboard.
   
4.  Connect all the other wires and their placement as can be seen in the diagram below.  

     <img src="..\images\in-person_workshops\mp3player\unomp3playerdiagram2.png" alt="audio_player" style="float:right;width:1200px;">



***Please note that the breadboard power rail must be connected to the 5V pin of the Arduino UNO, otherwise, the MP3 player module may not work properly.

5.  Launch the Arduino IDE. Use the provided USB cable to connect your Arduino board to your computer. 
   Open a new sketch by selecting File → New from the menu. Delete all the lines of codes for the file,

<img src="..\images\in-person_workshops\mp3player\newfile.png" alt="boardmanagerUNO" style="float:right;width:1200px;"> copy and paste to replace with this file:  https://github.com/uviclibraries/arduino/blob/audio-player/code/audioplayer.c



6. Install the Arduino UNO board package: Go to the menu of the Arduino IDE: Tools → Board → Boards Manager-search with keyword 'UNO' and click to install "Arduino AVR boards":
  <img src="..\images\in-person_workshops\mp3player\boardmanagerUNO.png" alt="boardmanagerUNO" style="float:right;width:1200px;">
 
 7.  Go to the menu of the Arduino IDE and then select Tools → Board → Arduino AVR Boards → Arduino UNO to enable communication with the board.:

<img src="..\images\in-person_workshops\mp3player\selectUNO.png" alt="boardmanager" style="float:right;width:1200px;">

Select board information window from Tools-Get board info menu, if it shows the information like below, it means that the Arduino UNO board has been connected to the Arduino IDE sussessfully:      
<img src="..\images\in-person_workshops\mp3player\boardinformation.png" alt="boardmanager" style="float:right;width:1200px;">


8. Select the Com port for the board from the Tools menu. The value of port number might be different for your board.
 <img src="..\images\in-person_workshops\mp3player\selectCom.png" alt="selectCom" style="float:right;width:1200px;">

 Also open the serial monitor window from the Tools menu: Tools-Serial monitor.

<img src="..\images\in-person_workshops\mp3player\serialmonitor.png" alt="serialmonitor" style="float:right;width:1200px;">
    

9. Press the arrow button and upload the codes to the board. Wait for a few seconds.
 <img src="..\images\in-person_workshops\mp3player\codeupload.png" alt="filepath" style="float:right;width:1200px;">
 
10.  In the Serial Monitor window, the system will continuously print distance information and system status.
 <img src="..\images\in-person_workshops\mp3player\audioplaying.png" alt="filepath" style="float:right;width:1200px;">
 

 When there is no object within 50 cm in front of the ultrasonic sensor, the audio player won't play and keep on outputting the distance information in the serial monitor window.

Place your hand or another object closer to the ultrasonic sensor (less than 50 cm), you will hear the music from the speaker! And the red or green LED will be on.

If your hands or other objects closer to the ultrasonic sensor (less than 20cm), you will hear another music from the speaker, both the red and green LEDs will turn on, and the
volume from the speakers can also change! Have fun!


11.  If you want to explore more, you can go back to the code editor of the Arduino IDE, modify the parameters or variables in the code, recompile, and upload your updated code to the Arduino board to see the results. For instance, change the distance threshold of starting playing
music from 50 cm to 80 cm to see whether it will actually happen.  Or you can change the music files, change the LEDs light,
change the volumes etc. or change whatever you want to fully control the program. Have more fun from it!

 
