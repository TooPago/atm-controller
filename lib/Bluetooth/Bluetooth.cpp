#include <Arduino.h>
#include "Bluetooth.h"
#include "Globals.h"
#include "Write.h"
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setupBluetooth()
{
    SerialBT.begin("ATM");
}

void loopReadBluetooth()
{
    if (SerialBT.available() > 0)
    {
        while (SerialBT.available())
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
}

void writeBluetooth(byte _send)
{
    SerialBT.write(_send);
}
