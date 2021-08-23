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

void readSerialLeds()
{
    if (inStringSerial != "")
    {
        bool check = false;
        if (inStringSerial == "A")
        {
            powerONLed(led_QR_LEFT);
            check = true;
        }
        else if (inStringSerial == "B")
        {
            powerOFFLed(led_QR_LEFT);
            check = true;
        }
        else if (inStringSerial == "C")
        {
            powerONLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "D")
        {
            powerOFFLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "E")
        {
            powerONLed(led_QR_LEFT);
            powerONLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "F")
        {
            powerOFFLed(led_QR_LEFT);
            powerOFFLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "E")
        {
            powerONLed(led_QR_LEFT);
            powerONLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "F")
        {
            powerOFFLed(led_QR_LEFT);
            powerOFFLed(led_QR_RIGHT);
            check = true;
        }
        else if (inStringSerial == "G")
        {
            powerONLed(led_FACE);
            check = true;
        }
        else if (inStringSerial == "H")
        {
            powerOFFLed(led_FACE);
            check = true;
        }
        else if (inStringSerial == "I")
        {
            powerONLed(led_DISPENSER);
            check = true;
        }
        else if (inStringSerial == "J")
        {
            powerOFFLed(led_DISPENSER);
            check = true;
        }
        else if (inStringSerial == "K")
        {
            powerONLed(led_ACCEPTOR);
            check = true;
        }
        else if (inStringSerial == "L")
        {
            powerOFFLed(led_ACCEPTOR);
            check = true;
        }
        else if (inStringSerial == "M")
        {
            powerONLed(led_NONE);
            check = true;
        }
        else if (inStringSerial == "N")
        {
            powerOFFLed(led_NONE);
            check = true;
        }
        else if (inStringSerial == "O")
        {
            powerONLed(led_QR_LEFT);
            powerONLed(led_QR_RIGHT);
            powerONLed(led_NONE);
            powerONLed(led_FACE);
            powerONLed(led_DISPENSER);
            powerONLed(led_ACCEPTOR);
            check = true;
        }
        else if (inStringSerial == "P")
        {
            powerOFFLed(led_QR_LEFT);
            powerOFFLed(led_QR_RIGHT);
            powerOFFLed(led_NONE);
            powerOFFLed(led_FACE);
            powerOFFLed(led_DISPENSER);
            powerOFFLed(led_ACCEPTOR);
            check = true;
        }

        if(check){
            Serial.write("Action Leds");
        }

    }
}