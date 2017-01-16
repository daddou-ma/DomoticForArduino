#include <Arduino.h>

#include "Pin.h"

Pin::Pin(String name, int number, PinType type)
{
  this->name = name;
  this->number = number;
  this->type = type;
}
