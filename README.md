# retropilot-drivetronik
sensors and actuators for retrofitting old vehicles with autonomy

Current parts list:

|Part          | Link        | 
|-------------- |-------------|
| 350mm Bearing | https://www.amazon.com/TamBee-Aluminum-Rotating-Turntable-Dining-Table/dp/B071FL5QR3/ref=sr_1_27?crid=I8JBQUCOKBSE&dchild=1&keywords=lazy+susan+bearing&qid=1611597016&sprefix=lazy+suzan+bea%2Caps%2C188&sr=8-27 | 
| Ball Bearings | https://www.amazon.com/uxcell-Groove-Bearings-Double-Shielded/dp/B0819927WR/ref=sr_1_6?dchild=1&keywords=3mm+ball+bearing&qid=1611150733&sr=8-6 |
AS504B Boards | https://www.mouser.com/ProductDetail/ams/AS5048B-TS_EK_AB?qs=Rt6VE0PE%2FOduJIB%252BRfeBZQ%3D%3D |
L298N driver | https://www.amazon.com/Qunqi-2Packs-Controller-Stepper-Arduino/dp/B01M29YK5U/ref=sr_1_6?crid=1M01FN9LFBNPM&dchild=1&keywords=l298n&qid=1611150995&sprefix=L298%2Caps%2C153&sr=8-6 |
ZT230 Stepper | you can probably find this on eBay |

<h2> Theory of Operation</h2>

the sensors are connected by I2C to an Arduino. this will be replaced with another micro soon, but currently it's being used to develop an algorithm for determining the absolute position of the actuator.

the stepper will be driven by field oriented control and will have a constant torque vector towards the zero position. this will be used to determine override and input torque without the need of a torque sensor.