
#include <Arduino.h>

#include "Pin.h"

Pin::Pin(String name, int number, PinType type)
{
  this->name = name;
  this->number = number;
  this->type = type;
  this->value = 0;
}

PinType Pin::getPinTypeFromString(String type) {
  if (type == "DIGITAL_OUTPUT") {
    return DIGITAL_OUTPUT;
  }
  else if (Type == "ANALOG_INPUT") {
    return ANALOG_INPUT;
  }
  else if (type == "SWITCH_OUTPUT") {
    return SWITCH_OUTPUT;
  }
  else if (type == "REMOTE_LED_OUTPUT") {
    return REMOTE_LED_OUTPUT;
  }
  else if (type == "DHT11_INPUT") {
    return DHT11_INPUT;
  }
  else if (type == "TEMPERATURE_ANALOG_INPUT") {
    return TEMPERATURE_ANALOG_INPUT;
  }
  else if (type == "HUMIDITY_ANALOG_INPUT") {
    return HUMIDITY_ANALOG_INPUT;
  }
  else {
    return NullType;
  }
}
