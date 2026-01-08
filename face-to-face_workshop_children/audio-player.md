---
layout: default
title: Audio Player
nav_order: 2
parent: Face-to-Face Workshop Activities
---

# Audio-player

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software){:target="_blank"} for either Windows or Mac, and then install the software on your computer.

    Materials needed:
 
    - 1 Arduino MKR Zero or MKR 1010 (see below)
    
     <img src="..\images\in-person_workshops\audio_player\arduino-mkr-zero.png" alt="arduino-mkr-zero" style="float:right;width:320px;">

    - HC-SR04 Ultrasonic sensor (see below)

      <img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="hc-sr04" style="float:right;width:320px;">

    - One LM386 amplifier board (see below)

<img src="..\images\in-person_workshops\audio_player\LM386.png" alt="LM386" style="float:right;width:320px;">
    
    - One speaker (see below)   
 <img src="..\images\in-person_workshops\audio_player\speaker.png" alt="speaker" style="float:right;width:220px;">    
    
    - One 32GB SD card with FAT file system and stored with a .wav audio file(test.wav)
  
3.   Make sure that the SD card have correct audio file(test.wav) and then insert the SD card into the SD card slot. 

4.  Connect the black wire to the **GND** pin on the Arduino and then the “**-**” pin on the breadboard.

5.  Connect the red wire to the **5V** pin on the Arduino and then the “**+**” pin on the breadboard.
   
6.  Connect all the other wires and their placement as can be seen in the diagram below.  

    <img src="..\images\in-person_workshops\audio_player\audio_player3.png" alt="audio_player" style="float:right;width:1200px;">

     Detailed explanation for the audio player application with Arduino Zero/MKR Zero/1000 WIFI can be referred to the link: https://docs.arduino.cc/tutorials/generic/simple-audio-player/ 
    
7.  Launch the arduino IDE.
   
8.  Using the provided USB cable to connect your Arduino board to your computer.

9.  Install the libraries for the MKR board: Go to the menu: Tools-boards manager-search with keyword 'MKR' and install
  <img src="..\images\in-person_workshops\audio_player\mkrinstall.png" alt="mkrinstall" style="float:right;width:1200px;">
  Go to the menu of the IDE and select Tools- boards manager again to select, connect and communicate with the board Auduino MKR Zero.
<img src="..\images\in-person_workshops\audio_player\boardmanager.png" alt="boardmanager" style="float:right;width:1200px;">
   
   
10.  Install the software libraries from the menu: Tools-libraries-search 'Audiozero'
     <img src="..\images\in-person_workshops\audio_player\audiozeroinstall.png" alt="audiozero" style="float:right;width:1200px;">

     
11. Select the com port for the board from the tools menu. Also open the serial port window from the tools menu.
    <img src="..\images\in-person_workshops\audio_player\selectcom.png" alt="boardmanager" style="float:right;width:1200px;">
    
12.  Open the project with below path:Your actual Arduino  directory\Arduino\libraries\AudioZero\examples\SimpleAudioPlayerZero\SimpleAudioPlayerZero.ino Delete the codes for the file and replace with this file:  https://drive.google.com/file/d/18EUg-kOSHI38W7ln0R3r6CeHl5sV-1iv/view?usp=sharing

    Press the arrow button and upload the codes to the board. Wait for a few seconds.
 <img src="..\images\in-person_workshops\audio_player\filepath.png" alt="filepath" style="float:right;width:1200px;">
 
12.  From the serial minitor window, you will see the test.wav file has been open and it keeps on printing out the distance information. Put your hands or other object closer to the ultrsonic sensor (less then 20cm), you will hear the music from the speaker! Enjoy the music!

***You might hear noises from the speaker, try to make the power source 'clean' or use filter to filter the noises, ask for help if it is needed.
 
