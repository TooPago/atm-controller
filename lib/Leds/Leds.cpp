#include <Arduino.h>
#include "Globals.h"
#include "Leds.h"

void setupLeds()
{
    pinMode(led_QR_LEFT, OUTPUT);
    pinMode(led_QR_RIGHT, OUTPUT);
    pinMode(led_NONE, OUTPUT);
    pinMode(led_FACE, OUTPUT);
    pinMode(led_DISPENSER, OUTPUT);
    pinMode(led_ACCEPTOR, OUTPUT);
}

void powerONLed(int led)
{
    digitalWrite(led, HIGH);
}

void powerOFFLed(int led)
{
    digitalWrite(led, LOW);
}
