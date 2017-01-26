#include <Arduino.h>

#include "AnalogInputPin.h"


AnalogInputPin::AnalogInputPin(uint8_t number, AnalogInputType analogType)
{
  this->number      = number;
  this->analogType  = analogtype;
  this->type        = AnalogInputPin;
}

float AnalogInputPin::getOriginalValue() {
  return this->value;
}

float AnalogInputPin::getValue() {
  switch(this->analogType) {
    case TEMPERATURE_CELSIUS:
      return getValueTempCelsuis();
      break;

    case TEMPERATURE_FAHR:
      return getValueTempfahr();
      break;

    case HUMIDITY:
      return getValueHumidity();
      break;

    case FIRE:
      getValueFire();
      break;

    default:
      return this->value;
      break;
  }
}

float AnalogInputPin::getValueTempCelsuis() {
  return (((this->value/1024.0)*5000) / 10);
}

float AnalogInputPin::getValueTempfahr() {
  return (((((this->value/1024.0)*5000) / 10) * 9) / 5 + 32);
}

float AnalogInputPin::getValueHumidity() {
  return this->value;
}

float AnalogInputPin::getValueFire() {
  return this->value;
}

AnalogInputType AnalogInputPin::getAnalogType() {
  return analogType;
}

bool AnalogInputPin::setPinMode()
{
  if (Config::getPinTypeByNumber(this->number) == ANALOG_PIN) {
    return true;
  }
  return false;
}

void AnalogInputPin::syncValue()
{
  this->value = analogRead(this->number);
}
