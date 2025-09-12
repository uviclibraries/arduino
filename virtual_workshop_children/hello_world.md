---
layout: default
title: Hello World
nav_order: 2
parent: Virtual Workshop Activities
customjs: http://code.jquery.com/jquery-1.4.2.min.js
---
<img src="..\images\virtual_workshops\hello_world\tinkercad_account.png" alt="tinkercad account" style="float:right;width:270px;">

# "Hello World" Blinking LED - Tinkercad

If you and your group have any questions or get stuck as you work through this in-class exercise, please ask the instructor for assistance.  Have fun!

1.  If you haven’t already, please go to the TinkerCad website and [create an account](https://www.tinkercad.com/){:target="_blank"}

    Once you have the account created, go to **Dashboard ->** select **Circuits** on the left side panel **->** select **Create new Circuit**

    Materials needed (all of the materials are located in the Basic Components section on the right side, except for wires. You can also search for items):
    <img src="..\images\virtual_workshops\hello_world\led_cartoon.png" alt="led" style="float:right;width:30px;">
    <img src="..\images\virtual_workshops\hello_world\resistor_cartoon.png" alt="resistor" style="float:right;width:90px;">
    - Arduino Uno R3
    - Breadboard Small
    - 1 LED light.
    - 1 220-ohm (or 220 Ω) Resistor with the following striping from left to right: red, red, brown, gold.

    Connect as shown in this diagram:

    <img src="..\images\virtual_workshops\hello_world\breadboard_schematic.png" alt="breadboard" style="width:480px;">

2.  Once everything is connected, click “Start Simulation” in the top right corner. You should see the light starting to blink

    <img src="..\images\virtual_workshops\hello_world\simulation.png" alt="simulation" style="width:480px;">

    <button onclick="toggle('gif1')">Show/Hide Animation</button>
<div id="gif1">
    <img src="..\images\virtual_workshops\hello_world\animated_breadboard.gif" alt="animated breadboard" style="width:480px;">
     </div> 

    

3.  For fun, let’s make the LED light blink faster.  In the top right section click **Code**, scroll to the bottom of the code and change the two lines that say, **delay(1000)** to **delay(250)**.  Press **Start Simulation** and see the difference.   Feel free to play around with the code to see what changes. Have fun!

    <img src="..\images\virtual_workshops\hello_world\code.png" alt="code" style="width:480px;">
    
    <button onclick="toggle('gif2')">Show/Hide Animation</button>
<div id="gif2">
      <img src="..\images\virtual_workshops\hello_world\animated_code.gif" alt="animated code" style="width:480px;">
     </div> 
  


<script>  

    function toggle(input) {
        var x = document.getElementById(input);
        if (x.style.display === "none") {
            x.style.display = "block";
        } else {
            x.style.display = "none";
        }
    }
</script>

[NEXT PROJECT: Love-o-Meter](love-o-meter.html){: .btn .btn-blue }
