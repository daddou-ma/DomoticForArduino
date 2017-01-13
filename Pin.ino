#include "Pin.h"

Pin::Pin(String name, uint8_t number, PinType type) 
{
  this->name = name;
  this->number = number;
  this->type = type;
}

