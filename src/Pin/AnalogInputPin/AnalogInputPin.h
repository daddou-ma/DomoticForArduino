#ifndef AnalogInputPin_H
#define AnalogInputPin_H
#include "../Pin.h"

enum AnalogInputType { TEMPERATURE_CELSIUS, TEMPERATURE_FAHR, HUMIDITY, FIRE};

class AnalogInputPin : public Pin
{
  protected:
    float            value;       // Value of the pin float
    AnalogInputType  analogType;  // Type (Temperature, Humidity, Fire etc ...)

  public:
    float getOriginalValue();

    float getValue();

    float getValueTempCelsuis();

    float getValueTempfahr();

    float getValueHumidity();

    float getValueFire();

    bool initPin();
};

#endif // AnalogInputPin_H
