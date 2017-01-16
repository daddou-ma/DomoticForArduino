#include <Arduino.h>

#include "AnalogInputPin.h"


    
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

bool AnalogInputPin::initPin() 
{
    // TODO
    return false;
}

