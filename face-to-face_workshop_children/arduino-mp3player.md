---
layout: default
title: Arduino MP3 Player
nav_order: 2
parent: Face-to-Face Workshop Activities
---

# Arduino MP3 Player

This page describes an Arduino audio player project using the Arduino [IDE](https://en.wikipedia.org/wiki/Integrated_development_environment) (software), an Arduino UNO R3 microcontroller board, a "[breadboard](https://en.wikipedia.org/wiki/Breadboard)", a YX5300 MP3 player module, and an active speaker.

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

If you haven’t already, please go to the Arduino website and [download the "Arduino IDE"](https://www.arduino.cc/en/Main/Software) for either Windows or Mac, and then install the software on your computer. If you do not want to, or are unable to, install the Arduino IDE software, you can use Arduino's cloud IDE. See our [Arduino cloud editor page](https://uviclibraries.github.io/arduino/face-to-face_workshop_children/cloud_IDE.html) for instructions on how to access Arduino's cloud IDE. 

## Materials needed
 
- Arduino UNO R3 breadboard (see below).
    
<img src="..\images\in-person_workshops\mp3player\arduino_r3.png" alt="arduino_r3" style="float:right;width:320px;">

- MP3 player with SD card shield slot and 3.5mm audio jack connector, which is already part of the YX5300 MP3 player board (see below).

<img src="..\images\in-person_workshops\mp3player\yx5300.png" alt="arduino_r3" style="float:right;width:320px;">
   
- HC-SR04 Ultrasonic distance sensor (see below)

<img src="..\images\in-person_workshops\audio_player\hc-sr04.png" alt="hc-sr04" style="float:right;width:320px;">
    
- One active (embedded with amplifier) speaker with audio cable connected to the YX5300 module (see below). The actual print output of the pin might be different (TX and RX are swapped). Follow the connections for the pin position.

<img src="..\images\in-person_workshops\mp3player\sharkspeaker.png" alt="speaker" style="float:right;width:220px;">    
    
- An SD card that has at least one audio file (.wav or .mp3 format) saved to it. Note that the file storage type must be [FAT](https://en.wikipedia.org/wiki/File_Allocation_Table).

- Name for your audio file(s) in the following format: two-digit file number + three characters + file extension—for example: 01tet.wav or 02ply.mp3.

Audio files have to be stored in the top-level directory of the SD drive. You can use folders or folders with three-digit names, such as 001, 002, 003, etc.

2. Make sure that the SD card has correct audio file type, file name, and folder name before you insert the SD card into the SD card slot. 
3. Connect a black wire from the GND pin on the Arduino breadboard to the “-” (ground) rail on the breadboard.
   Connect a red wire from the **5V** pin on the Arduino breadboard to the “**+**”(power) rail on the breadboard.
4. Connect all the other wires and their placement as can be seen in the diagram below. Important: the breadboard power rail must be connected to the 5V pin of the Arduino UNO, otherwise, the MP3 player module may not work properly.
   ![Arduino with ultrasonic seinsor mp3 board, led lights and powered speaker](../images/in-person_workshops/mp3player/unomp3playerdiagram3.png)
6. On your computer, launch the Arduino IDE software. Use the provided USB cable to connect your Arduino breadboard to your computer. 
   In the Arduino IDE software, open a new "sketch", or file, by selecting File → New from the menu. Next, delete all the lines of code in your newly created file. We are going to replace that code... 
<img src="..\images\in-person_workshops\mp3player\newfile.png" alt="boardmanagerUNO" style="float:right;width:1200px;"> 
7. On your computer, open a web browser and go to [https://github.com/uviclibraries/arduino/blob/audio-player/code/audioplayer.c
](https://github.com/uviclibraries/arduino/blob/audio-player/code/audioplayer.c). Copy/paste the code on that page into your newly created file. 
8. Now, we need to install the Arduino UNO board package. In the Arduino IDE software, go to the menu and select Tools → Board → Boards Manager. In the search bar of the Boards Manager window, search for "UNO." Click on the "Arduino AVR boards" package to install it.
<img src="..\images\in-person_workshops\mp3player\boardmanagerUNO.png" alt="boardmanagerUNO" style="float:right;width:1200px;">
9.  In In the Arduino IDE software, go to the menu and select Tools → Board → Arduino AVR Boards → Arduino UNO to enable communication with the breadboard.
<img src="..\images\in-person_workshops\mp3player\selectUNO.png" alt="boardmanager" style="float:right;width:1200px;">

Select the breadboard information window from Tools → Get Board Info menu. If your menu shows the same information depcited below, then your Arduino UNO breadboard has connected successfully to the Arduino IDE software file editor. 

<img src="..\images\in-person_workshops\mp3player\boardinformation.png" alt="boardmanager" style="float:right;width:1200px;">

9. Select the Com port for the board from the Tools menu. Note that the default value of port number might be different than shown below.

<img src="..\images\in-person_workshops\mp3player\selectCom.png" alt="selectCom" style="float:right;width:1200px;">

Next, open the Serial Monitor window from the Tools menu by selecting Tools → Serial Monitor.

<img src="..\images\in-person_workshops\mp3player\serialmonitor.png" alt="serialmonitor" style="float:right;width:1200px;">

10. Click on the arrow button and upload the codes to the breadboard. Note that your code may take a few seconds to upload.

<img src="..\images\in-person_workshops\mp3player\codeupload.png" alt="filepath" style="float:right;width:1200px;">
 
Now it is time to test if things are working! 

Note that in the In the Serial Monitor window, the system will continuously print distance information and system status.

<img src="..\images\in-person_workshops\mp3player\audioplaying.png" alt="filepath" style="float:right;width:1200px;">

When there is no object within 50 cm in front of the ultrasonic sensor, the audio player will not play, but will continue outputting the distance information in the Serial Monitor window.

Place your hand or another object closer to the ultrasonic sensor (less than 50 cm) and you should hear music from the speaker! Note that lights on the breadboard should also activate.

If you place your hand or other objects closer to the ultrasonic sensor (less than 20cm), then you should hear another music file play from the speaker. And, both breadboard lights should activate. **Important:** make sure that your speaker is switched on and that the volume is turned up (click on the "V+" button a few time). Note that you may need to click on the speaker's "M" button to activate the right mode for the speaker—this is a quirk of the speakers we are using and has nothing to do with our Arduino programming! If you see a tiny, blinking red light on the YX5300 MP3 player module, then your music file is currently playing. 

**All done!** 

## Next steps
If you want to do more tweaking, you can go back to the Arduino code editor and modify the parameters or variables in the code, recompile, and upload your updated code to the Arduino board to see the results. For example, you could change the sensor's distance threshold from 50 cm to 80 cm. Or, you could add or change the music files, change the LEDs lights, or change the speaker volume, and more.  etc. or change 

If something is not working for you, please remember to ask your instructor for help. 

Finally, we have another Arduino audio player workshop, using the Arduino MKR WiFi 1010 or MKR Zero. See [https://uviclibraries.github.io/arduino/face-to-face_workshop_children/audio-player.html](Audio Player) for more.


 
