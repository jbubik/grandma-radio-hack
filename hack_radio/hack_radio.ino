#include <avr/sleep.h>

#define PIN_VUSB  PB3  // pin 2 (V_USB detection) - needs 10k pull down resistor
#define PIN_MODE  PB0  // pin 5 (MODE button emulation signal - active pull low, otherwise HighZ)

void setup() {
    pinMode(PIN_VUSB, INPUT); digitalWrite(PIN_VUSB, LOW); //INPUT HighZ
    pinMode(PIN_MODE, INPUT); digitalWrite(PIN_MODE, LOW); //INPUT HighZ
    delay(1000); // RADIO Power stabilizes, wait here

    while (digitalRead(PIN_VUSB) == LOW) { // wait for Power ON button AND USB mode
        delay(10);
    }

    delay(2000); // wait for possible ON button release (only one button recognized simultaneously)
    digitalWrite(PIN_MODE, LOW); pinMode(PIN_MODE, OUTPUT); //OUTPUT, LOW - activate button MODE
    delay(500);
    pinMode(PIN_MODE, INPUT); digitalWrite(PIN_MODE, LOW); //INPUT HighZ - stop button press

    delay(500);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();  //AVR GOES OFF, sleep well until next power cycle
}

void loop() {
    // never gets here
}