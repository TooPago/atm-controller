#include <Arduino.h>
#include "SoftwareSerial.h"
#include "Globals.h"
#include "Write.h"
#include "TP11.h"
#include "Leds.h"

SoftwareSerial SerialTP11;

void reloadTP11()
{
    delay(50);
    SerialTP11.write(0x02);
    delay(50);
    SerialTP11.write(0x3E);
    delay(50);
    SerialTP11.write(0x5E);
    delay(50);
    powerOFFLed(led_ACCEPTOR);
}

void setupTP11()
{
    SerialTP11.begin(9600, SWSERIAL_8E1, RX_TP11, TX_TP11, false, 256);
    reloadTP11();
}

void readTP11()
{
    if (SerialTP11.available() > 0)
    {
        while (SerialTP11.available())
        {
            byte byteSerial = SerialTP11.read();
            if (byteSerial != 0x80 && byteSerial != 0x81)
            {
                write(0x4A, byteSerial);
            }
        }
    }
}

void readSerialTP11()
{
    if (byteCommand == 0x4A)
    {
        SerialTP11.write(byteAction);
        if (byteAction == 0x3E)
        {
            powerONLed(led_ACCEPTOR);
        }
        else if (byteAction == 0x5E)
        {
            powerOFFLed(led_ACCEPTOR);
        }
    }
}

void restartTP11()
{
    SerialTP11.write(0x30);
    reloadTP11();
}