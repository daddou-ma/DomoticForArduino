
#include <Arduino.h>

#include "Pin.h"

Pin::Pin(uint8_t number, PinType type)
{
  this->number = number;
  this->type = type;
}

PinType Pin::getPinTypeFromString(String type) {
  if (type == "DIGITAL_OUTPUT") {
    return DIGITAL_OUTPUT;
  }
  else if (type == "ANALOG_INPUT") {
    return ANALOG_INPUT;
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
