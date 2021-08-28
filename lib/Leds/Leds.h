#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>
#include "Globals.h"

void setupLeds(void);
void powerONLed(int led);
void powerOFFLed(int led);
void readSerialLeds();
void restartLeds();
void OnAllLeds();

#endif