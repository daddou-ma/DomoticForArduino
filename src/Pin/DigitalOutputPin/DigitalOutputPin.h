#ifndef DigitalOutputPin_H
#define DigitalOutputPin_H
#include "../Pin.h"

class DigitalOutputPin : public Pin
{
  protected:
    bool  value;   // Value of the pin HIGH or LOW

  public:
    bool getValue();

    void setValue(bool val);

    bool initPin();
};

#endif // DigitalOutputPin_H
