#ifndef DigitalOutputPin_H
#define DigitalOutputPin_H
#include "../Pin.h"

class DigitalOutputPin : public Pin
{
  protected:
    bool  value;   // Value of the pin HIGH or LOW

  public:
    DigitalOutputPin(uint8_t);

    bool getValue();

    void setValue(bool val);

    bool setPinMode();
};

#endif // DigitalOutputPin_H
