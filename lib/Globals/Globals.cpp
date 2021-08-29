#include <Arduino.h>
#include "Globals.h"

/*Leds*/
int led_QR_LEFT = 12;
int led_QR_RIGHT = 14;
int led_FACE = 25;
int led_DISPENSER = 26;
int led_ACCEPTOR = 27;

/*Serial*/
byte byteCommand = 0x00;
byte byteAction = 0x00;
int countByte = 0;
unsigned long LAST_STATUS = millis();
bool CHECK_STATUS = true;
bool debug = false;

/*Coin Acceptor*/
int pinCoinAcceptor = 21;
unsigned long LASTIMPULSE = 0;
int PULSES = 0;
bool acceptCoin = false;
const int timeLimitPulsesCoin = 500;
const int timeDelayPulsesCoin = 100;

/*Reset*/
int pin_reset = 5;
unsigned long LASTRESET = 0;
const int timeReset = 5000;

/*TP11*/
int RX_TP11 = 13;
int TX_TP11 = 22;

/*Hopper*/
int pinHopper = 32;
int relayHopper = 33;
unsigned long LASTIMPULSEHOPPER = 0;
int PULSESHOPPER = 0;
bool hopperCoin = false;
int timeLimitPulsesHopper = 500;
int numCoinsHopper = 0;
int timeWaitHopper = 30000;