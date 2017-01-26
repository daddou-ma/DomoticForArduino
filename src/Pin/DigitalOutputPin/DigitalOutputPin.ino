#include <Arduino.h>

#include "DigitalOutputPin.h"

DigitalOutputPin::DigitalOutputPin(uint8_t number) {
  this->number  = number;
  this->type    = DigitalOutputPin;
}

bool DigitalOutputPin::getValue()
{
  return this->value;
}

void DigitalOutputPin::setValue(bool val)
{
  this->value = val;
  digitalWrite(this->number, this->value);
}

bool DigitalOutputPin::setPinMode()
{
  pinMode(this->number, OUTPUT)
  return true;
}
