#ifndef DigitalDHTPin_H
#define DigitalDHTPin_H
#include "Pin.h"

typedef struct DHT DHT;

struct DHT {
  float            temperature;       // Value of the pin float
  float            humidity;       // Value of the pin float
};

class DigitalDHTPin : public Pin
{
  protected:
    DHT    value;
    
  public:
    DHT getValue();
    
    float getTemperature();
     
    float getHumidity();
    
    bool initPin();
};

#endif // DigitalDHTPin_H
