#ifndef Pin_H
#define Pin_H

#include <Arduino.h>

enum PinType {DIGITAL_OUTPUT = 1, ANALOG_INPUT = 2, REMOTE_LED_OUTPUT, DHT11_INPUT, TEMPERATURE_ANALOG_INPUT, HUMIDITY_ANALOG_INPUT, NullType};

class Pin {
  public:
    uint8_t  number;  // Pin Number
    uint16_t  value;  // Pin Number
    PinType  type;    // Type of Pin (INPUT or OUTPUT)

    Pin(uint8_t , PinType);
    static PinType getPinTypeFromString(String type);
};

#endif // Pin_H
