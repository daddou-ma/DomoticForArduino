#ifndef Config_H
#define Config_H

#include <Arduino.h>

#define TIMER               3
#define START_PIN           0
#define COUNT_PIN           20
#define DIGITAL_PIN_COUNT   12
#define ANALOG_PIN_COUNT    6
#define RESERVED_PIN_COUNT  2

enum DataTypePin:int {
  ANALOG_PIN = 0, DIGITAL_PIN = 1, RESERVED_PIN = 2
};

class Config
{
public:

    static String id;
    static int    timer;
    static int    startPin;
    static int    countPin;
    static int    digitalPinCount;
    static int    analogPinCount;
    static int    reservedPinCount;

    static DataTypePin getPinTypeByNumber(int pin);
};

#endif // Config_H
