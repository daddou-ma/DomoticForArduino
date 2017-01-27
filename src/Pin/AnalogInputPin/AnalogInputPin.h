#ifndef AnalogInputPin_H
#define AnalogInputPin_H
#include "../Pin.h"
#include "../../Config.h"

enum AnalogInputType:uint8_t { TEMPERATURE_CELSIUS = 0, TEMPERATURE_FAHR = 1, HUMIDITY = 2, FIRE = 3};

class AnalogInputPin : public Pin
{
  protected:
    float            value;       // Value of the pin float
    AnalogInputType  analogType;  // Type (Temperature, Humidity, Fire etc ...)

  public:
    AnalogInputPin(uint8_t , AnalogInputType);

    float getValue();

    AnalogInputType getAnalogType();

    bool setPinMode();

    void syncValue();
};

#endif // AnalogInputPin_H
