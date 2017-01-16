#ifndef Pin_H
#define Pin_H

#include <Arduino.h>

enum PinType {DIGITAL_OUTPUT, ANALOG_INPUT, SWITCH_OUTPUT, REMOTE_LED_OUTPUT, DHT11_INPUT, TEMPERATURE_ANALOG_INPUT, HUMIDITY_ANALOG_INPUT};

class Pin {
  protected:
    String   name;
    int  number;  // Pin Number
    PinType  type;    // Type of Pin (INPUT or OUTPUT)
    bool     enabled; // is The Pin Enabled

  public:
    Pin(String , int , PinType);
};

#endif // Pin_H
