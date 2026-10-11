---
layout: page
title: "Halloween Workshop: Make Your Own Box Monster"
---

# Halloween Workshop: Make Your Own Box Monster

If you have questions or get stuck during this workshop, please ask the instructor for help. Have fun!

Before you begin, download and install the Arduino IDE for your operating system from the official Arduino software page: https://www.arduino.cc/en/software/
or use the cloud editor version.

## Materials

1.  2 LEDs (any colour)

2.  1 shoebox

3.  1 220 Ω or 560 Ω resistor

4.  6 × 1 kΩ resistors (colour bands: brown, black, red, gold)

5.  7 jumper wires (at least 2 long wires)

6.  4 alligator-clip leads

7.  2 ping-pong balls

8.  Openings for the ping-pong-ball eyes (prepared by the instructor)

9.  1 8 Ω speaker

Connect the components as shown in the diagram below. Leave the speaker disconnected for now; we will add it later.

<img src="..\images\in-person_workshops\spooky\image2.png">

1.  Using the provided USB cable, connect the Arduino to your computer.

2.  Launch the Arduino IDE.

3.  Open the sketch at [the original sketch](https://github.com/uviclibraries/arduino/blob/federerlee-spookyworkshop/code/spooky.c) and copy its code into a new Arduino sketch.

4.  In the Arduino IDE, select **Arduino Uno** as the board. In IDE 2, use the board selector; in older versions, use Tools → Board.

    1.  On macOS, open the port selector and choose the port for your Arduino. It may begin with /dev/tty.usbmodem or /dev/cu.usbmodem.

    2.  On Windows, open the port selector and choose the COM port associated with your Arduino Uno.

5.  Click **Upload** (the right-arrow icon in the toolbar).

<img src="..\images\in-person_workshops\spooky/image5.gif" />

6.  Check that the LEDs are on. Cover the photoresistor with your finger; the LEDs should turn off. They should turn on again when you uncover the sensor.

7.  Open the Serial Monitor. You should see readings from 0 to 1023. These values represent the light level detected by the sensor. The reading should decrease as you cover the photoresistor and may reach 0 when it is fully covered.

<img src="..\images\in-person_workshops\spooky/image3.png" /><img src="..\images\in-person_workshops\spooky/image21.png" />

8.  Now make the ping-pong-ball eyes. Ask the instructor to prepare an X-shaped opening in each ball. If the ball has a pupil, point it upward; otherwise, draw one with a black marker. Remove the LEDs, insert one into each ball, and return the LED legs to their original breadboard positions.

9.  Remove the photoresistor from the breadboard. Position it so that the box lid covers it when the box is closed. Ask the instructor to prepare two small openings in the box beneath the lid’s edge, then pass the photoresistor legs through them. Connect each leg to a jumper wire using an alligator clip, then plug the jumper wires into the breadboard holes where the photoresistor legs were connected.

<img src="..\images\in-person_workshops\spooky/image16.jpg" /><img src="..\images\in-person_workshops\spooky/image18.jpg" />

10. Test your box monster by opening and closing the lid.

11. You did it—congratulations!

> **Optional:** Change the colour of the monster’s eyes by editing the values passed to `setColor()`. For example, `(0, 0, 255)` produces blue in RGB colour notation. Choose an RGB colour and replace the three numbers in `setColor()` with its red, green, and blue values.**

> **Challenge:** Can you make the eyes change colour or cycle through several colours? Try the [colour-cycling example](https://goo.gl/BahchB). Check that the link still works before publishing, and ask the instructor for help if needed.

**Now let’s add some sound!**

## Add a Spooky Sound

1.  Using the remaining two alligator clips, connect the speaker’s red wire to Arduino pin 11 and its black wire to GND (ground).

<img src="..\images\in-person_workshops\spooky/image17.jpg" />

<img src="..\images\in-person_workshops\spooky/image14.png" />

**Note: The diagram uses a piezo buzzer (the black circle) to represent the speaker. The speaker used in this workshop does not have legs.**

2.  Choose a short sound file for your monster. The original workshop recommends keeping it under 4 seconds because the audio is stored in the Arduino sketch and memory is limited. Confirm that you have permission to use the sound before including it in a public project. You can explore [Freesound Effects](https://www.freesoundeffects.com/).

3.  Convert the sound file to the format required by the workshop code. The original instructions use [an online audio converter](https://audio.online-convert.com/convert-to-mp3). Check that the service and its settings are still available before running the workshop.

<img src="..\images\in-person_workshops\spooky/image13.png" />

4.  Next, install the PCM library. In the Arduino IDE, open the Library Manager (in older versions: Sketch → Include Library → Manage Libraries) and search for “PCM.”

<img src="..\images\in-person_workshops\spooky/image7.png" />

5.  Find the library listed as “PCM” by David Mellis and Michael Smith, if it is still available. Select it and click **Install**. Library names and availability can change, so verify that the installed version is compatible with the workshop sketch.

<img src="..\images\in-person_workshops\spooky/image15.png" />

6.  Open the sketch at [the sound-enabled sketch](https://goo.gl/D2HQNm) and copy its code into the Arduino IDE, replacing the previous sketch code.

7.  Download the EncodeAudio program from [the EncodeAudio program](https://goo.gl/FguCKz). The original program requires Java. Before publishing, verify that this download is still available and safe to use, and document any current installation requirements.

<img src="..\images\in-person_workshops\spooky/image9.png" />

8.  Run EncodeAudio and select the converted audio file. The program should copy the encoded sample data to your clipboard.

9.  Paste the copied sample data between the curly braces in the declaration that begins `const unsigned char sample[] PROGMEM`.

<img src="..\images\in-person_workshops\spooky/image4.png" />

10. Upload the updated sketch to the Arduino board.

11. Decorate your monster and box as you like. Have fun!

> **You may keep the box. The Arduino, breadboard, and other components may be borrowed for one week from the Music and Media desk on the first floor. Ask the DSC staff for current borrowing details.**
