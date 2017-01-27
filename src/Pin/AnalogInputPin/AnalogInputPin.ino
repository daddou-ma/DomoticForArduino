#include <Arduino.h>
#include "AnalogInputPin.h"


AnalogInputPin::AnalogInputPin(uint8_t number, AnalogInputType analogType)
{
  this->number      = number;
  this->analogType  = analogtype;
  this->type        = AnalogInputPin;
}

float AnalogInputPin::getValue() {

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
