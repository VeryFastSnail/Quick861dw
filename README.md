## **Quick 861DW custom firmware**

This REPO is a place for developers to get better firmware for quick 861DW hot air soldering station. 

**How it started?**
I had my station stopped working on me one night and I found out that main issue of it was that micro controller was bad, since quick team used atmega16a and internal flash for it's firmware I was stuck with a glory peace of metal just sitting there. So I ordered few Attiny16a micro controllers and started experimenting with dead maijn board. 
 
 **What are my plans?**
I already started to reverse engineer main board. It's quite simple, mcu is used to control triac and triac controls 24v AC signal to heater inside the gun. Temperature is sensed from the tip and OP07C opamp is used to amplify it. then signal is carried directly to the MCU. Long story short it's quite simple hardware, but the firmware is the key.

**What is the advantages?**
Quick 861DW is cheap (sub $300) and it's great value for the money. But there are some thing to be approved. So while designing our own firmware we can include what ever we want. For example it has a beeper, that beeps every time station boots, I hate it. So while creating station firmware It could be disabled, or enabled with help of configuration menu in service buttons combination.

**What inside?**
Station has many parts that are jelly bean. So datasheets are commonly available.
Here is the list of interesting parts:

 - MCU - ATMEGA16A 
 - OPAMP - OP07C
 - TRIAC - BTA41600B
 - TRIAC controller - MOC3041
 - LCD - Custom segment LCD, I suspect it uses EDS803 driver or something similar
  All other components are simple resistors transistors and other random stuff
  
**Schematics**
I tried to draw schematics of it as simple as possible for firmware so it's still work in progress, but this is what I have right now.

![schematic_image](https://raw.githubusercontent.com/VeryFastSnail/Quick861dw/master/Pictures/MCU_pinout.jpg)

There are more, but for now I only share main mcu.