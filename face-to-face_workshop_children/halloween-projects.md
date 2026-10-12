---
layout: page
title: "Halloween Arduino Projects: Button Monster and Motion-Activated Haunted Display"
---

# More Halloween Arduino Projects: Projects C and D

These projects extend the Box Monster workshop with a **servo motor** that moves a lightweight prop, such as a box lid, door, curtain, or sign. You can trigger the movement with a push button, a PIR motion sensor, an HC-SR04 ultrasonic distance sensor, or a combination of these inputs.

> **Workshop note:** Projects C and D need additional components and a different Arduino sketch from the original Box Monster. Treat the wiring and code as a new build. Test the mechanism before adding decorations, and ask the instructor for help with wiring or code.

## Shared design idea: Make the servo part of the character

The servo should look like it belongs in the Halloween decoration, rather than an exposed motor added afterward.

- **Monster box:** Hide the servo inside the box. Connect its horn to the lid with a short, lightweight cardboard or craft-stick linkage so the monster can pop open.
- **Haunted door:** Mount the servo behind a cardboard wall or doorframe. Attach the horn to a small hinge or lightweight flap.
- **Curtain or tomb:** Use the servo to pull a lightweight paper curtain, uncover a skeleton/eyeball, or lift a tombstone flap. A simple string linkage can work if it does not snag.
- **Moving sign:** Have the servo rotate a lightweight “BOO!” sign or reveal a hidden message.
- **Hide the hardware:** Cover the servo with a cardboard housing decorated as a stone, coffin, tree stump, monster body, or haunted-house wall. Leave enough clearance for the horn and linkage to move freely.

Keep the moving part lightweight, use a hinge where possible, and leave the servo horn and linkage clear of fingers, wires, and loose craft materials. Do not force the lid or servo by hand when the mechanism is powered.

### Shared materials

- Arduino board and USB cable
- Breadboard and jumper wires
- One small hobby servo motor and its compatible mounting hardware
- A lightweight cardboard lid, door, flap, sign, or curtain
- Craft supplies available at the workshop, such as a box, ping-pong balls, eyeball balls, pom-poms, chenille stems, stickers, glitter foam shapes, twine, spiderweb decorations, or rubber bats
- Optional: LEDs and suitable resistors for eyes or accent lighting
- One or more trigger devices: push button, PIR motion sensor, and/or HC-SR04 ultrasonic distance sensor
- A suitable servo power supply if required by the servo; check the servo's voltage and current requirements

**Power and wiring safety:** A servo can draw more current than an Arduino board's 5 V pin can reliably supply. Follow the instructor's wiring diagram and use a suitable supply when needed. If the servo has a separate supply, connect its ground to Arduino GND so the control signal has a common reference. Do not connect a motor's power leads directly to an Arduino I/O pin.

---

## Project C: Trick-or-Treat Button Monster

Build a monster that waits for a visitor to press a button, then opens its mouth or box lid, reveals glowing eyes, or pops up a small “TRICK OR TREAT!” sign.

<img src="..\\images\\in-person_workshops\\spooky\\image16.jpg" />
<img src="..\\images\\in-person_workshops\\spooky\\image18.jpg" />

### How it works

1. The monster waits with its mouth or lid closed.
2. A visitor presses a large, clearly labelled button.
3. The servo opens the mouth/lid or raises a sign.
4. Optional LEDs light up, and the monster can make a short sound if the workshop sound setup is used.
5. After a short pause, the servo returns the moving part to its closed position.

### What you need

- A small cardboard box or monster-shaped body with a lightweight hinged lid or mouth
- One servo motor, mounted inside the box or behind the monster's face
- One push button, preferably mounted on a sturdy cardboard “Press for a surprise!” panel
- Arduino, breadboard, jumper wires, and an appropriate servo power arrangement
- Optional LEDs and resistors for glowing eyes; optional speaker/buzzer if supported by the sketch
- Craft supplies to create the monster's face, teeth, tongue, claws, and button panel

### Make it your own

1. Build the monster body from a shoebox or another small cardboard box. Decide whether the moving part will be the lid, mouth, a small door, or a pop-up sign.
2. Attach the moving part with a simple hinge. Make sure it opens easily by hand before installing the servo.
3. Mount the servo inside the box or behind a cardboard panel. Attach the servo horn to the lid or mouth using a lightweight linkage. Ask the instructor to help position the servo so it does not push past the hinge's natural range.
4. Mount the push button where visitors can easily reach it. Keep the button and wires away from the moving lid and linkage.
5. Connect the button and servo according to the instructor's wiring diagram, then upload the Project C sketch. Test the servo movement before attaching decorations.
6. Add eyes, teeth, a tongue, foam shapes, pom-poms, or chenille-stem horns. Make a decorative cover for the servo, but leave the moving parts free to travel.
7. Test several times. Adjust the linkage or the open/closed positions in the sketch if the lid binds or the servo strains.

**Decoration idea — “Feed the monster”:** Make the button look like a candy button or doorbell. Give the monster a large cardboard mouth with foam teeth. When pressed, the mouth opens to reveal a paper tongue, glowing eyes, or a small candy-shaped sign. Keep real candy and small loose craft pieces away from electrical parts and young children.

**Try this:** Add a short delay before the mouth opens, blink the eyes while it is open, or let the visitor press the button again to close it.

---

## Project D: Motion-Activated Haunted Display

Create a haunted scene that reacts when someone approaches. A cardboard haunted-house door can swing open, a tombstone can lift, an eyeball can appear behind a flap, or a small ghost can rise from a box.

<img src="..\\images\\in-person_workshops\\spooky\\image2.png" />
<img src="..\\images\\in-person_workshops\\spooky\\image16.jpg" />

### Choose a trigger

Use **one trigger to start with**, then add another if time allows.

- **PIR motion sensor:** Detects movement in its field of view. It is a good choice when the display should react as a person walks past. It does not measure exact distance, and its response can vary with the sensor and environment.
- **HC-SR04 ultrasonic distance sensor:** Measures the distance to an object in front of it. It can trigger the effect when a visitor comes within a chosen range, provided the sensor has a clear view and the target reflects the sound well.
- **Push button:** Provides a manual trigger for testing or for visitors who want to activate the display themselves.
- **Combination:** For example, use PIR motion to activate the display, an HC-SR04 to limit activation to someone standing close, and a button as a manual test/override. Combining sensors requires extra wiring and logic in the sketch; start with one sensor to keep the build manageable.

### What you need

- A stable cardboard base or small haunted-house/tomb/crypt scene
- One servo motor and a lightweight moving part (door, flap, sign, curtain, or pop-up figure)
- One trigger device to start: PIR, HC-SR04, or push button
- Arduino, breadboard, jumper wires, and an appropriate servo power arrangement
- Optional LEDs and resistors for glowing eyes or scene lighting
- Craft supplies such as spiderweb material, eyeball balls, rubber bats, twine, stickers, glitter foam shapes, and cardboard

### Make it your own

1. Choose a simple scene: a haunted-house door, a tomb with a lifting lid, an eyeball behind a flap, or a ghost that rises from a box.
2. Build a stable base and add a hinge or guide for the moving part. Keep the prop light enough for the servo to move without straining.
3. Mount the servo behind a wall, inside a box, or beneath the base. Use a short linkage or string to move the prop, and test the range before adding decorations.
4. Mount the selected sensor so it can detect visitors without being blocked by the decoration. For an HC-SR04, leave the two round transducers exposed and point them toward the approach area. For a PIR sensor, leave its white sensor lens unobstructed.
5. Connect the sensor and servo according to the instructor's diagram. Upload the Project D sketch and test the sensor readings and movement separately before combining them.
6. Set the trigger behaviour: for example, open the door when motion is detected, keep it open briefly, then close it. Add a cooldown period so the servo does not repeatedly move while someone remains nearby.
7. Decorate the servo housing as part of the scene: a stone wall, coffin, tree stump, haunted-house frame, or pile of “rubble.” Keep the sensor's view and the servo's movement path clear.
8. Test from different distances and angles. Adjust sensor placement and the sketch with the instructor's help if it triggers too easily or misses visitors.

**Decoration ideas — choose one moving reveal:**

- **Haunted-house door:** Put the servo behind a cardboard doorframe and connect it to a lightweight hinged door. Add a paper doorknob and fake stone blocks around the frame.
- **Eyeball crypt:** Hide an eyeball behind a small tomb lid. The lid lifts when someone approaches; LEDs behind the eyeball create a glowing effect.
- **Spiderweb curtain:** Mount a lightweight paper or fabric-like web curtain across a doorway. The servo pulls it aside to reveal a spider or eyeball. Keep loose webbing away from the horn and linkage.
- **Pop-up ghost:** Hide a paper ghost on a lightweight arm inside a box. The servo lifts the arm so the ghost appears over the top edge.

**Try this:** Make the display open only when someone comes close, then close after a few seconds. For an advanced version, require both PIR motion and a nearby HC-SR04 reading, or let a button trigger the same sequence manually.

> **Important:** PIR and HC-SR04 sensors work differently and need different wiring and code. The original Box Monster sketch does not automatically support these sensors or the servo. Use a separate, instructor-tested sketch for Project C or D, verify the servo's safe travel range, and test the complete mechanism before the workshop. Keep moving parts lightweight and avoid pinch points.
