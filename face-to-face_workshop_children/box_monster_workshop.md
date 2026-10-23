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

3.  Open the sketch at [the monsterbox1 sketch](../code/monsterbox1.c) and copy its code into a new Arduino sketch.

4.  In the Arduino IDE, select **Arduino Uno** as the board. In IDE 2, use the board selector; in older versions, use Tools → Board.

    1.  On macOS, open the port selector and choose the port for your Arduino. It may begin with /dev/tty.usbmodem or /dev/cu.usbmodem.

    2.  On Windows, open the port selector and choose the COM port associated with your Arduino Uno.

5.  Click **Upload** (the right-arrow icon in the toolbar).

<img src="..\images\in-person_workshops\spooky/image5_new.png" />

6.  Check that the LEDs are on. Cover the photoresistor with your finger; the LEDs should turn off. They should turn on again when you uncover the sensor.

7.  Open the Serial Monitor. You should see readings from 0 to 1023. These values represent the light level detected by the sensor. The reading should decrease as you cover the photoresistor and may reach 0 when it is fully covered.

<img src="..\images\in-person_workshops\spooky/image3_new.png" />

8.  Now we will insert the LEDs into your ping pong ball “eyes.” Cut some slits in the ping pong balls with the craft knife. Cut an X into the side of the ping pong ball (with the pupil facing up; if there’s no pupil, you can draw one with a black sharpie). Take out the LEDs and insert each one into a ping pong ball. Stick the LED legs back into the breadboard in their original position.

<img src="..\images\in-person_workshops\spooky/image21.png" />

9.  Take the photoresistor out of the breadboard. We want to detect when the box is open so we want to place it somewhere it will be covered when the box is closed. Cut two slits into the box under the lip of the lid and stick the photoresistor legs through each slit. Using two alligator clips,clip each leg of the photoresistor to a jumper wire. Then plug each end of the jumper wire into the spots where the photoresistor legs used to be.


<img src="..\images\in-person_workshops\spooky/image16.jpg" /><img src="..\images\in-person_workshops\spooky/image18.jpg" />

10. Test your box monster by opening and closing the lid.

11. You did it—congratulations!

> **Optional:** Change the colour of the monster’s eyes by editing the values passed to `setColor()`. For example, `(0, 0, 255)` produces blue in RGB colour notation. Choose an RGB colour and replace the three numbers in `setColor()` with its red, green, and blue values.**

> **Challenge:** Can you make the eyes change colour or cycle through several colours? Try the [colour-cycling example code](../code/monsterbox_rgb.c). Check that the link till works before publishing, and ask the instructor for help if needed.

**Now let’s add some sound!**

## Add a Spooky Sound

1.  Using the remaining two alligator clips, connect the speaker’s red wire to Arduino pin 11 and its black wire to GND (ground).

<img src="..\images\in-person_workshops\spooky/image17.jpg" />

<img src="..\images\in-person_workshops\spooky/image14_update.png" />

**Note: The diagram uses a piezo buzzer (the black circle) to represent the speaker. The speaker used in this workshop does not have legs.**

2.  Choose a short sound file for your monster. The original workshop recommends keeping it under 4 seconds because the audio is stored in the Arduino sketch and memory is limited. Confirm that you have permission to use the sound before including it in a public project. You can explore [Freesound Effects](https://www.freesoundeffects.com/).

3.  Convert the sound file to the format required by the workshop code. For wav file, we can use [online-converter.com](https://audio.online-convert.com/convert-to-wav). Check that the service and its settings are still available before running the workshop.

Settings need to choose to down-sample the audio to 8 KHz, 8-bit mono sound:

<img src="..\images\in-person_workshops\spooky/huantyhouse_onlineconvert.png" />

Alternatively, use: https://g711.org/

<img src="..\images\in-person_workshops\spooky/g711org.png" />

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

---

# More Halloween Decoration Ideas

The following projects use the same basic Arduino circuit and components as the Box Monster above. You do not need to rebuild the circuit from scratch: start with the working Box Monster setup, then adapt the decoration and, if you like, make small changes to the sketch. Ask the instructor for help if you are unsure how to adjust the circuit or code.

## Project A: Peek-a-Boo Monster Box

Turn your Box Monster into a surprise decoration! When the box is closed, the lid covers the photoresistor. When someone opens the box, the sensor detects the light and the monster's eyes respond.

<img src="..\images\in-person_workshops\spooky/Peek-a-Boo.jpg" />
<img src="..\images\in-person_workshops\spooky/Peek-a-Boo2.jpg" />

### What you need

- The working Box Monster Arduino circuit described above, including the LEDs and photoresistor
- A small box with a lid
- Ping-pong balls or eyeball balls for the eyes
- Craft supplies such as stickers, glitter foam shapes, chenille stems, pom-poms, letter beads, or other decorations available at the workshop

### Make it your own

1. Decorate the outside of the box to create a monster, haunted creature, or any character you like.
2. Use the ping-pong balls or eyeball balls as the eyes. If using ping-pong balls, ask the instructor to prepare any openings needed to fit the LEDs.
3. Position the photoresistor so the closed lid covers it and opening the lid exposes it to light. The detailed wiring steps are in the main Box Monster instructions above.
4. Upload and test the Box Monster sketch. Open and close the lid to see how the eyes respond.
5. If time permits, customize the eye colour or blinking behaviour by changing the sketch with help from the instructor.

**Try this:** Can you make the monster look sleepy when the box is closed and surprised when it opens? Change its face and decorations to match the effect.

## Project B: Haunted Eyeball or Spiderweb Display

Use the same LEDs and photoresistor circuit to create a glowing Halloween decoration without using a box. Make a cluster of glowing eyeballs, a spiderweb scene, or a spooky mini display.

<img src="..\images\in-person_workshops\spooky/spider_web1.jpg" />
<img src="..\images\in-person_workshops\spooky/haunting_eyes.jpg" />

### What you need

- The working Box Monster Arduino circuit described above, including LEDs and the photoresistor
- Ping-pong balls or eyeball balls for the eyes (or another lightweight decoration that can be illuminated by LEDs)
- A small cardboard base or other stable display surface
- Available craft supplies such as spiderweb material, rubber bats, twine, chenille stems, stickers, glitter foam shapes, pom-poms, or letter beads

### Make it your own

1. Create a spiderweb or spooky scene on your display base. Arrange the eyeballs wherever you want them to appear.
2. Place the LEDs inside or behind the eyeballs. Ask the instructor to help prepare any openings and secure the decorations safely.
3. Keep the photoresistor exposed to the room light, where it can detect changes in brightness. The main Box Monster sketch uses this sensor to control the LEDs; your instructor can help you adapt the sensor placement and behaviour for your display.
4. Test the LEDs and decorate the display around the circuit. Make sure craft materials do not pull on the wires or cause short circuits.
5. For an extra challenge, try changing the blink timing or eye colours in the sketch. The main instructions above explain how to upload the sketch and edit the colour settings.

**Try this:** Make the eyes glow in a dark corner, or design a spiderweb display with several eyes watching visitors. The exact effect will depend on the sensor placement and any changes you make to the sketch.

> **Note:** These are decoration variations, not separate pre-tested circuit designs. They reuse the Box Monster electronics, but the photoresistor may need to be repositioned and the sketch may need adjustment for the desired effect. Test your design with the instructor before decorating over or enclosing the circuit.

