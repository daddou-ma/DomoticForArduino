#ifndef Pin_H
#define Pin_H

#include <Arduino.h>

enum PinType {DIGITAL_OUTPUT, ANALOG_INPUT, REMOTE_LED_OUTPUT, DHT11_INPUT, TEMPERATURE_ANALOG_INPUT, HUMIDITY_ANALOG_INPUT, NullType};

class Pin {
  public:
    String   name;
    int  number;  // Pin Number
    int  value;  // Pin Number
    PinType  type;    // Type of Pin (INPUT or OUTPUT)
    bool     enabled; // is The Pin Enabled

    Pin(String , int , PinType);
    static PinType getPinTypeFromString(String type);
};

#endif // Pin_H
