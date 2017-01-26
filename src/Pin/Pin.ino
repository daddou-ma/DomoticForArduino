
#include <Arduino.h>

#include "Pin.h"

Pin::Pin(uint8_t number, PinType type)
{
  this->number = number;
  this->type = type;
}

bool setPinMode() {
  // TODO : not defined type of pin
  return false;
}
