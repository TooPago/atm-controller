#ifndef BLUETOOH_H
#define BLUETOOH_H

#include <Arduino.h>
#include "Globals.h"
#include "BluetoothSerial.h"

extern BluetoothSerial SerialBT;

void setupBluetooth();
void loopReadBluetooth();
void writeBluetooth(byte _send);

#endif