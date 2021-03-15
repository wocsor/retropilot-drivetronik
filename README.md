# retropilot-drivetronik
sensors and actuators for retrofitting old vehicles with autonomy

Current parts list:

|Part                 | Link        | 
|--------------       |-------------| 
| Small Ball Bearings | https://www.amazon.com/gp/product/B075CM3FG3/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1 |
| Idler Bearings      | https://www.amazon.com/gp/product/B07BPHRSN5/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1 |
| AS504B Boards       | https://www.mouser.com/ProductDetail/ams/AS5048B-TS_EK_AB?qs=Rt6VE0PE%2FOduJIB%252BRfeBZQ%3D%3D |
| L298N driver        | https://www.amazon.com/Qunqi-2Packs-Controller-Stepper-Arduino/dp/B01M29YK5U/ref=sr_1_6?crid=1M01FN9LFBNPM&dchild=1&keywords=l298n&qid=1611150995&sprefix=L298%2Caps%2C153&sr=8-6 |
| NEMA23 Stepper      | https://www.amazon.com/gp/product/B00PNEPF5I/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1 |
|

### TOTAL COST: $90.35
Plus a bunch of spare H bridges and bearings, because Amazon is now Costco if you want to buy Prime.

## Theory of Operation

the sensors are connected by I2C to an Arduino. this will be replaced with another micro soon, but currently it's being used to develop an algorithm for determining the absolute position of the actuator.

the stepper will be driven by field oriented control and will have a constant torque vector towards the zero position. this will be used to determine override and input torque without the need of a torque sensor.