#include <Arduino.h>
#include "Write.h"
//#include "Bluetooth.h"

void write(byte _device, byte _command)
{
    byte msg[2];
    msg[0] = _device;
    msg[1] = _command;
    Serial.write(msg, 2);
    // delay(50);
    // Serial.write(_command);
    //writeBluetooth(_device);
    //writeBluetooth(_command);
}