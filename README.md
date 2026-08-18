# PROBLEM DESCRIPTION
Grandma has a radio, type is HYUNDAI TR 1088 SU3 BS (manufactured by ETA under license).
The default mode after first power-on is "USB mode". MODE button must be pressed to switch to "FM mode".
While powered the radio retains the mode in RAM.
This hack uses AVR (ATtiny13A) to switch the radio to "FM mode" automatically.
After first action the AVR goes to sleep mode indefinitely. The radio operates normally after this first "kick".

Grandma is happy, everybody is happy...

## turning Arduino Nano into ISP programmer
- open Arduino IDE
- File -> Examples -> 11.ArduinoISP -> ArduinoISP
- flash to Arduino Nano
- if using USB2Serial chip onboard the Nano (CH340/FT232), connect after uploading either (not both):
    - pull-up resistor (110R to 120R) between RST and 5V.
    - capacitor 10uF or larger between RST(+) and GND(-).

## programming AVR (ATtiny13)
More info about MicroCore on https://github.com/MCUdude/MicroCore

- open Arduino IDE
- File ->Preferences -> Additional boards manager URLs -> https://mcudude.github.io/MicroCore/package_MCUDude_MicroCore_index.json
- Tools -> Board -> Board manager / find and install MicroCore
- Open sketch "hack_radio.ino"
- Tools -> Board: switch board to ATtiny13
- Tools -> Port: COM3
- Tools -> BOD: 4.7V
- Tools -> Bootloader: No bootloader
- Tools -> Clock: 1.2MHz internal osc.
- Tools -> EEPROM: not retained
- Tools -> Programmer: Arduino as ISP
- Tools -> Burn Bootloader
- Sketch -> Compile & Upload

## used Signals
- pin 4 - GND - ground, connect to any suitable place on PCB
- pin 8 - Vcc - 5V power supply (comes from internal power source immediately after connecting MAINS), connect to any suitable place on PCB
- pin 2 - Vusb - 5V trigger, radio is ON and in "USB mode" (otherwise floating and needs 10k pull-down resistor), connect near USB port
- pin 5 - MODE - output signal that emulates the button press (the tactile switch connects ground potential), connect to the tactile switch (to the switching pin, not GND pin)
![Schematics](img/05%20schematics.png)

## Assembly
See images for inspiration. Use your skills to hack this together.

![Type label](img/01%20radio%20type.png)
![Top view](img/02%20radio%20top%20view.png)
![Inside](img/03%20radio%20inside.png)
![Pinout](img/04%20pinout%20ATtiny13.png)

