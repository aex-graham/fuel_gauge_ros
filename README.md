Materials:
* Jumper wire: x2
* 220 Ω resistor: x2
* Jumper wire to alligator clip: x2
* Breadboard: x1
* Arduino Due: x1
* USB-A to Micro-USB cord: x1
* Rochester Sensors 9840: x1 (can be purchased [here](https://spartanzeroturnparts.com/kg-stand-on-fuel-sending-unit/)) (Referred to as gauge)

Tools:
* Needle nosed pliers (for removing the gauge’s plug’s connector)
* Pokey tool (for removing the gauge’s plug’s connector)

Assembly:
* The gauge’s black wire is connected (via a jumper wire to alligator clip) to 5v. The white wire goes row 50.
* One resistor is connected to rows 45 and 50.
* One jumper wire is connected to row 45 and the analog read pin (I chose A7).
* One resistor is connected to rows 40 and 45.
* One jumper wire is connected to row 40 and GND.

![IMG_2692](https://github.com/aex-graham/fuel_gauge_ros/assets/107943530/103250b0-62f5-490d-b8b6-f19b2fcab802)
(Ignore all the extra flat wires and the circuit board)

Runnin the code:
* Run `roscore` in one terminal 
* Run `rosrun rosserial_python serial_node.py _port:=/dev/<your usb port>` in another terminal
* To see the output, run `rostopic echo /percent_full` in another terminal
