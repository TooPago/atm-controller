#include <Arduino.h>
#include "Write.h"
//#include "Bluetooth.h"

void write(byte _send)
{
    Serial.write(_send);
    //writeBluetooth(_send);
}