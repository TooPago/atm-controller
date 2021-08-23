#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Leds.h"
#include "Serial.h"

void setup() {
  Serial.begin(38400);
  setupLeds();
}

void loop() {
  SerialRead();
}