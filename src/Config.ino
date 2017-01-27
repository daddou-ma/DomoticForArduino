#include <Arduino.h>

#include "Config.h"

String Config::id    = "000000AA";
uint8_t Config::timer    = TIMER;



DataTypePin Config::getPinTypeByNumber(uint8_t pin) {

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
