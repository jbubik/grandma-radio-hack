

1. Arduino Nano as ISP programmer
- open Arduino IDE
- File -> Examples -> 11.ArduinoISP -> ArduinoISP
- flash to Arduino Nano
- if using USB2Serial chip onboard the Nano (CH340/FT232), connect after programming either (not both):
-- pull-up resistor (110R to 120R) between RST and 5V.
-- capacitor 10uF or larger between RST(+) and GND(-).

2. ATtiny13 programming (more on https://github.com/MCUdude/MicroCore)
- open Asruino IDE
- File ->Preferences -> Additional boards manager URLs -> https://mcudude.github.io/MicroCore/package_MCUDude_MicroCore_index.json
- Tools -> Board -> Board manager / find and install MicroCore
- Open sketch
- Tools -> Board: switch board to ATtiny13
- Tools -> Port: COM3
- Tools -> BOD: 4.7V
- Tools -> Bootloader: No bootloader
- Tools -> Clock: 1.2MHz internal osc.
- Tools -> EEPROM: not retained
- Tools -> Programmer: Arduino as ISP
- Tools -> Burn Bootloader
- Sketch -> Compile & Upload


