#ifndef Config_H
#define Config_H

#include <Arduino.h>

#define TIMER               3
#define START_PIN           2
#define COUNT_PIN           20

enum DataTypePin:uint8_t {
  ANALOG_PIN = 0, DIGITAL_PIN = 1, RESERVED_PIN = 2
};

class Config
{
public:

    static String id;
    static uint8_t    timer;

    static DataTypePin getPinTypeByNumber(uint8_t pin);
};

#endif // Config_H
