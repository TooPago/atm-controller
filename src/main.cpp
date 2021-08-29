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
//#include "Bluetooth.h"

void setup()
{
  Serial.begin(38400);
  setupLeds();
  setupCoinAcceptor();
  setupReset();
  setupTP11();
  setupHopper();
  //setupBluetooth();
  restartLeds();
  restartCoinAcceptor();
  restartStatus();
  restartHopper();
  write(0x0A, 0x0A);
}

void loop()
{
  SerialRead();
}