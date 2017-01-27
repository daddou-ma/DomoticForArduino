#ifndef DigitalDHTPin_H
#define DigitalDHTPin_H
#include "../Pin.h"
#include <DHT.h>

#define DHTTYPE DHT11

typedef struct DhtValue DhtValue;

struct DhtValue {
  float            temperature;       // Value of the pin float
  float            humidity;       // Value of the pin float
};

class DigitalDHTPin : public Pin
{
  protected:
    DhtValue    value;
    DHT         dht;

  public:
    DigitalDHTPin(uint8_t);

    DhtValue getValue();

    bool setPinMode();
};

#endif // DigitalDHTPin_H
