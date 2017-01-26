#include <Arduino.h>
#include "DigitalDHTPin.h"

DigitalDHTPin::DigitalDHTPin(uint8_t number) {
  this->number = number;
  this->type   = DHT_INPUT;
}

DhtValue DigitalDHTPin::getValue() {
  return this->value;
}

float DigitalDHTPin::getTemperature() {
  return this->value.temperature;
}

float DigitalDHTPin::getHumidity() {
  return this->value.humidity;
}

bool DigitalDHTPin::setPinMode()
{
  dht(this->number, DHTTYPE))
  dht.begin();

  return true;
}

void DigitalDHTPin::syncValue()
{
    this->value.temperature = this->dht.readTemperature();
    this->value.humidity = this->dht.readHumidity();
}
