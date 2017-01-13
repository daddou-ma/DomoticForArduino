#include "DigitalOutputPin.h"


bool DigitalOutputPin::getValue() 
{
  return this->value;
}

void DigitalOutputPin::setValue(bool val) 
{
  this->value = val;
  digitalWrite(this->number, this->value);
}

bool DigitalOutputPin::initPin()
{
    // TODO
    return false;
}
