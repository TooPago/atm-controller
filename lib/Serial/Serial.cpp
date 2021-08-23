#include <Arduino.h>
#include "Serial.h"
#include "Leds.h"

void SerialRead()
{
    inStringSerial = "";
    if (Serial.available() > 0)
    {
        while (Serial.available())
        {
            char inChar = Serial.read();
            inStringSerial = String(inChar);
        }
    }

    if(inStringSerial != ""){

    }

}