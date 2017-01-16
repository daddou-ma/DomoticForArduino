#include <Arduino.h>

#include "Config.h"

int Config::timer    = TIMER;
int Config::startPin = START_PIN;
int Config::countPin = COUNT_PIN;

int Config::digitalPinCount   = DIGITAL_PIN_COUNT;
int Config::analogPinCount    = ANALOG_PIN_COUNT;
int Config::reservedPinCount  = RESERVED_PIN_COUNT;

DataTypePin Config::getPinTypeByNumber(int pin) {

  switch (pin) {
    case 0:
    case 1:
      return RESERVED_PIN;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      return DIGITAL_PIN;
      break;
    case 0xA0:
    case 0xA1:
    case 0xA2:
    case 0xA3:
    case 0xA4:
    case 0xA5:
      return ANALOG_PIN;
      break;
    default:
      return RESERVED_PIN;
      break;
  }
}
