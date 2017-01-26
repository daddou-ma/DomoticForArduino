#ifndef Pin_H
#define Pin_H

#include <Arduino.h>

enum PinType:int {DIGITAL_OUTPUT = 0, ANALOG_INPUT = 1, DHT_INPUT = 2, NullType = -1};

class Pin {
  public:
    uint8_t  number;  // Pin Number
    uint8_t  value;  // Pin Number
    PinType  type;    // Type of Pin (INPUT or OUTPUT)

    Pin(uint8_t , PinType);
    bool setPinMode();
};

#endif // Pin_H
