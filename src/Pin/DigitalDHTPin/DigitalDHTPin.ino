#include <Arduino.h>

#include "DigitalDHTPin.h"


DHT DigitalDHTPin::getValue() {
  return this->value;
}

float DigitalDHTPin::getTemperature() {
  return this->value.temperature;
}

float DigitalDHTPin::getHumidity() {
  return this->value.humidity;
}

bool DigitalDHTPin::initPin()
{
    // TODO
    return false;
}
