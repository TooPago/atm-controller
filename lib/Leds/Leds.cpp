#include <Arduino.h>
#include "Globals.h"
#include "Write.h"
#include "Leds.h"

void setupLeds()
{
    pinMode(led_QR_LEFT, OUTPUT);
    pinMode(led_QR_RIGHT, OUTPUT);
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

void readSerialLeds()
{
    if (byteCommand == 0x8A)
    {
        bool check = false;
        if (byteAction == 0x80)
        {
            powerONLed(led_QR_LEFT);
            powerONLed(led_QR_RIGHT);
            check = true;
        }
        else if (byteAction == 0x81)
        {
            powerOFFLed(led_QR_LEFT);
            powerOFFLed(led_QR_RIGHT);
            check = true;
        }
        else if (byteAction == 0x82)
        {
            powerONLed(led_FACE);
            check = true;
        }
        else if (byteAction == 0x83)
        {
            powerOFFLed(led_FACE);
            check = true;
        }
        else if (byteAction == 0x84)
        {
            powerONLed(led_DISPENSER);
            check = true;
        }
        else if (byteAction == 0x85)
        {
            powerOFFLed(led_DISPENSER);
            check = true;
        }
        else if (byteAction == 0x86)
        {
            powerONLed(led_ACCEPTOR);
            check = true;
        }
        else if (byteAction == 0x87)
        {
            powerOFFLed(led_ACCEPTOR);
            check = true;
        }
        else if (byteAction == 0x88)
        {
            powerONLed(led_QR_LEFT);
            powerONLed(led_QR_RIGHT);
            powerONLed(led_FACE);
            powerONLed(led_DISPENSER);
            powerONLed(led_ACCEPTOR);
            check = true;
        }
        else if (byteAction == 0x89)
        {
            powerOFFLed(led_QR_LEFT);
            powerOFFLed(led_QR_RIGHT);
            powerOFFLed(led_FACE);
            powerOFFLed(led_DISPENSER);
            powerOFFLed(led_ACCEPTOR);
            check = true;
        }

        if (check)
        {
            write(0x8A);
        }
    }
}

void restartLeds()
{
    powerOFFLed(led_QR_LEFT);
    powerOFFLed(led_QR_RIGHT);
    powerOFFLed(led_FACE);
    powerOFFLed(led_DISPENSER);
    powerOFFLed(led_ACCEPTOR);
}

void OnAllLeds()
{
    powerONLed(led_QR_LEFT);
    powerONLed(led_QR_RIGHT);
    powerONLed(led_FACE);
    powerONLed(led_DISPENSER);
    powerONLed(led_ACCEPTOR);
}