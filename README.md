# fuel_gauge_ros

This is a Ros node to read data off a Rochester Sensors 9840 fuel gauge.

Materials:
* Jumper wire: x2
* 220 Ω resistor: x2
* Jumper wire to alligator clip: x2
* Breadboard: x1
* Arduino Due: x1
* USB-A to Micro-USB cord: x1
* Rochester Sensors 9840: x1 (can be purchased here) (Referred to as gauge)

Tools:
* Needle nosed pliers (for removing the gauge’s plug’s connector)
* Pokey tool (for removing the gauge’s plug’s connector)

Assembly:
* Remove the gauge's plug's connector
* The gauge’s black wire is connected (via a jumper wire to alligator clip) to 5v. The white wire goes row 50.
* One resistor is connected to rows 45 and 50.
* One jumper wire is connected to row 45 and the analog read pin (I chose A7).
* One resistor is connected to rows 40 and 45.
* One jumper wire is connected to row 40 and GND.

These row numbers can be changed as you see fit, but if you want to change the pin number, you'll have to change that in the .ino file too
