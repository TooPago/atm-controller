#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Write.h"
#include "Leds.h"
#include "CoinAcceptor.h"
#include "Serial.h"
#include "Status.h"
#include "Reset.h"
//#include "Bluetooth.h"

void setup()
{
  Serial.begin(38400);
  setupLeds();
  setupCoinAcceptor();
  setupReset();
  //setupBluetooth();
  restartLeds();
  restartCoinAcceptor();
  restartStatus();
  write(0x0A);
}

void loop()
{
  SerialRead();
}