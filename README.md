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

![circuit](https://github.com/aex-graham/fuel_gauge_ros/assets/107943530/411199a5-5ee6-4ef5-84df-e830020ed912)

Runnin the code:
* Open `FuelGaugeReader.ino` in the Arduino IDE
* Install the `rosserial` library from `Tools > Manage Libraries`
* Use the Arduino IDE to load the code into your board
* Run `roscore` in one terminal 
* Run `rosrun rosserial_python serial_node.py _port:=/dev/<your usb port>` in another terminal
* To see the output, run `rostopic echo /fuel_level_percent_full` in another terminal
