#include <Arduino.h>
#include "Serial.h"
#include "Write.h"
#include "Globals.h"
#include "Leds.h"
#include "CoinAcceptor.h"
#include "Status.h"
#include "Reset.h"
#include "TP11.h"
//#include "Bluetooth.h"

void SerialRead()
{
    byteCommand = 0x00;
    byteAction = 0x00;
    countByte = 0;

    if (Serial.available() > 0)
    {
        while (Serial.available())
        {
            byte byteSerial = Serial.read();

            if (countByte == 0)
            {
                byteCommand = byteSerial;
            }
            else if (countByte == 1)
            {
                byteAction = byteSerial;
            }

            countByte += 1;

            if (debug == true)
            {
                write(byteSerial);
            }
        }
    }

    //loopReadBluetooth();

    if (byteCommand != 0x00 && byteAction != 0x00)
    {
        readSerialLeds();
        loopSerialCoinAcceptor();
        readSerialStatus();
        serialReset();
        readSerialTP11();
    }

    loopCoinAcceptor();
    loopStatus();
    loopReset();
    readTP11();

    delay(10);
}