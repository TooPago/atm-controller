#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Write.h"
#include "Leds.h"
#include "CoinAcceptor.h"
#include "Serial.h"
#include "Status.h"
#include "Reset.h"
#include "TP11.h"
#include "Hopper.h"
#include "Bluetooth.h"
#include "XC100.h"

void setup()
{
  Serial.begin(38400);
  setupLeds();
  setupCoinAcceptor();
  setupReset();
  setupTP11();
  setupHopper();
  setupBluetooth();
  setupXC100();
  restartLeds();
  restartCoinAcceptor();
  restartStatus();
  restartHopper();
  restartXC100();
  LAST_STATUS = millis();
  write(0x0A, 0x0A);
}

void loop()
{
  SerialRead();
}