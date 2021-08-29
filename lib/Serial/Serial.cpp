#include <Arduino.h>
#include "Serial.h"
#include "Write.h"
#include "Globals.h"
#include "Leds.h"
#include "CoinAcceptor.h"
#include "Status.h"
#include "Reset.h"
#include "TP11.h"
#include "Hopper.h"
#include "Bluetooth.h"

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
                write(byteSerial, byteAction);
            }
        }
    }

    if (byteCommand != 0x00 && byteAction != 0x00)
    {
        readSerialLeds();
        loopSerialCoinAcceptor();
        readSerialStatus();
        serialReset();
        readSerialTP11();
        readSerialHopper();
    }

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommand = byteCommandBLE;
        byteAction = byteActionBLE;
        readSerialLeds();
        loopSerialCoinAcceptor();
        readSerialStatus();
        serialReset();
        readSerialTP11();
        readSerialHopper();
    }

    loopCoinAcceptor();
    loopStatus();
    loopReset();
    readTP11();
    loopHopper();
    loopReadBluetooth();

    if (byteCommandBLE != 0x00 && byteActionBLE != 0x00)
    {
        byteCommandBLE = 0x00;
        byteActionBLE = 0x00;
    }

    delay(10);
}