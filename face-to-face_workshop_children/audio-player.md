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
    <img src="..\images\in-person_workshops\audio_player\arduino-mkr-zero.png" alt="arduino-mkr-zero" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\audio_player\LM386.png" alt="LM386" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="hc-sr04" style="float:right;width:120px;">
    <img src="..\images\in-person_workshops\audio_player\speaker.png" alt="speaker" style="float:right;width:120px;">
    - 1 Arduino MKR Zero or MKR 1010 (see below)
    - HC-SR04 Ultrasonic sensor (see below)
    - 1 LM386 amplifier board (see below)
    - 1 speaker (see below)
    - 1 32GB SD card (see below)

    - See Below for the remaining wires and their placement
  
2.   Make sure that the SD card have correct audio file(test.wav) and then insert the SD card into the SD card slot. 

3.  Connect the black wire to the **GND** pin on the Arduino and then the “**-**” pin on the breadboard.

4.  Connect the red wire to the **5V** pin on the Arduino and then the “**+**” pin on the breadboard.
   
5.  Connect all the other wires as can be seen in the diagram below.

    <img src="..\images\in-person_workshops\audio_player\audio_player3.png" alt="audio_player" style="float:right;width:1200px;">

     Detailed explanation for the audio player application with Arduino Zero/MKR Zero/1000 WIFI can be referred to the link: https://docs.arduino.cc/tutorials/generic/simple-audio-player/ 
    
6.  Launch the arduino IDE.
   
7.  Using the provided USB cable to connect your Arduino board to your computer.

8.  Install the libraries for the MKR board: Go the menu: tool-board manager-search with keyword 'MKR' and install
  <img src="..\images\in-person_workshops\audio_player\mkrinstall.png" alt="mkrinstall" style="float:right;width:1200px;">
  Go to the menu of the IDE and select Tool- boards manager again to connect and communicate with the board Auduino MKR Zero.
<img src="..\images\in-person_workshops\audio_player\boardmanager.png" alt="boardmanager" style="float:right;width:1200px;">
   
   
9.  Install the software libraries from the menu: Tool-library-search 'Audiozero'
     <img src="..\images\in-person_workshops\audio_player\audiozeroinstall.png" alt="audiozero" style="float:right;width:1200px;">

     
10. Select the com port for the board from the tool manu. Open the serial port window.
    <img src="..\images\in-person_workshops\audio_player\selectcom.png" alt="boardmanager" style="float:right;width:1200px;">
    
11.  Open the project with below path:Your Arduino IDE path\Arduino\libraries\MKRZero\examples\SimpleAudioPlayerZero\SimpleAudioPlayerZero.io Delete the codes for the file and replace with this file:  Press the arrow button and upload the codes to the board. Wait for a few seconds.
 <img src="..\images\in-person_workshops\audio_player\filepath.png" alt="filepath" style="float:right;width:1200px;">
 
12.  From the serial minitor window, you will see the test.wav file has been open and it keeps on printing out the distance information. Put your hands or other object closer to the ultrsonic sensor (less then 20cm), you will hear the music from the speaker! Enjoy the music!
***You might hear noises from the speaker, try to make the power source 'clean' or use filter to filter the noises, ask for help!
 
