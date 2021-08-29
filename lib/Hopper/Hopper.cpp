#include <Arduino.h>
#include "Hopper.h"
#include "Globals.h"
#include "Write.h"
#include "Leds.h"

void ICACHE_RAM_ATTR hopper_event();

int totalCoins(byte _total)
{
    switch (_total)
    {
    case 0x00:
        return 0;
    case 0x01:
        return 1;
    case 0x02:
        return 2;
    case 0x03:
        return 3;
    case 0x04:
        return 4;
    case 0x05:
        return 5;
    case 0x06:
        return 6;
    case 0x07:
        return 7;
    case 0x08:
        return 8;
    case 0x09:
        return 9;
    case 0x10:
        return 10;
    case 0x11:
        return 11;
    case 0x12:
        return 12;
    case 0x13:
        return 13;
    case 0x14:
        return 14;
    case 0x15:
        return 15;
    case 0x16:
        return 16;
    case 0x17:
        return 17;
    case 0x18:
        return 18;
    case 0x19:
        return 19;
    case 0x20:
        return 20;
    case 0x21:
        return 21;
    case 0x22:
        return 22;
    case 0x23:
        return 23;
    case 0x24:
        return 24;
    case 0x25:
        return 25;
    case 0x26:
        return 26;
    case 0x27:
        return 27;
    case 0x28:
        return 28;
    case 0x29:
        return 29;
    case 0x30:
        return 30;
    case 0x31:
        return 31;
    case 0x32:
        return 32;
    case 0x33:
        return 33;
    case 0x34:
        return 34;
    case 0x35:
        return 35;
    case 0x36:
        return 36;
    case 0x37:
        return 37;
    case 0x38:
        return 38;
    case 0x39:
        return 39;
    case 0x40:
        return 40;
    case 0x41:
        return 41;
    case 0x42:
        return 42;
    case 0x43:
        return 43;
    case 0x44:
        return 44;
    case 0x45:
        return 45;
    case 0x46:
        return 46;
    case 0x47:
        return 47;
    case 0x48:
        return 48;
    case 0x49:
        return 49;
    case 0x50:
        return 50;
    case 0x51:
        return 51;
    case 0x52:
        return 52;
    case 0x53:
        return 53;
    case 0x54:
        return 54;
    case 0x55:
        return 55;
    case 0x56:
        return 56;
    case 0x57:
        return 57;
    case 0x58:
        return 58;
    case 0x59:
        return 59;
    case 0x60:
        return 60;
    case 0x61:
        return 61;
    case 0x62:
        return 62;
    case 0x63:
        return 63;
    case 0x64:
        return 64;
    case 0x65:
        return 65;
    case 0x66:
        return 66;
    case 0x67:
        return 67;
    case 0x68:
        return 68;
    case 0x69:
        return 69;
    case 0x70:
        return 70;
    case 0x71:
        return 71;
    case 0x72:
        return 72;
    case 0x73:
        return 73;
    case 0x74:
        return 74;
    case 0x75:
        return 75;
    case 0x76:
        return 76;
    case 0x77:
        return 77;
    case 0x78:
        return 78;
    case 0x79:
        return 79;
    case 0x80:
        return 80;
    case 0x81:
        return 81;
    case 0x82:
        return 82;
    case 0x83:
        return 83;
    case 0x84:
        return 84;
    case 0x85:
        return 85;
    case 0x86:
        return 86;
    case 0x87:
        return 87;
    case 0x88:
        return 88;
    case 0x89:
        return 89;
    case 0x90:
        return 90;
    case 0x91:
        return 91;
    case 0x92:
        return 92;
    case 0x93:
        return 93;
    case 0x94:
        return 94;
    case 0x95:
        return 95;
    case 0x96:
        return 96;
    case 0x97:
        return 97;
    case 0x98:
        return 98;
    case 0x99:
        return 99;
    }
    return 0;
}

void setupHopper()
{
    pinMode(pinHopper, INPUT_PULLUP);
    pinMode(relayHopper, OUTPUT);
    digitalWrite(relayHopper, LOW);
}

void startHopper()
{
    LASTIMPULSEHOPPER = millis();
    PULSESHOPPER = 0;
    hopperCoin = true;
    attachInterrupt(digitalPinToInterrupt(pinHopper), hopper_event, RISING);
    digitalWrite(relayHopper, HIGH);
    powerONLed(led_DISPENSER);
}

void finishHopper()
{
    detachInterrupt(digitalPinToInterrupt(pinHopper));
    digitalWrite(relayHopper, LOW);
    powerOFFLed(led_DISPENSER);
    LASTIMPULSEHOPPER = 0;
    PULSESHOPPER = 0;
    numCoinsHopper = 0;
    hopperCoin = false;
}

void hopper_event()
{
    if (hopperCoin == true)
    {

        int lastPulseHopper = PULSESHOPPER;

        if ((millis() - LASTIMPULSEHOPPER) >= timeLimitPulsesHopper && PULSESHOPPER > 0)
        {
            PULSESHOPPER += 1;
            LASTIMPULSEHOPPER = millis();
        }
        else if (PULSESHOPPER == 0)
        {
            PULSESHOPPER += 1;
            LASTIMPULSEHOPPER = millis();
        }

        if (lastPulseHopper != PULSESHOPPER)
        {
            write(0x3C);
        }
    }
}

void readSerialHopper()
{
    if (byteCommand == 0x3A)
    {
        if (byteAction == 0x3A)
        {
            finishHopper();
            write(0x3B);
        }
        else
        {
            numCoinsHopper = totalCoins(byteAction);
            startHopper();
            write(0x3A);
        }
    }
}

void loopHopper()
{
    if (hopperCoin == true)
    {
        if (PULSESHOPPER >= numCoinsHopper)
        {
            hopperCoin = false;
            delay(50);
            finishHopper();
        }
        if ((millis() - LASTIMPULSEHOPPER) >= timeWaitHopper)
        {
            hopperCoin = false;
            delay(50);
            finishHopper();
            write(0x3B);
        }
    }
}

void restartHopper()
{
    finishHopper();
}
