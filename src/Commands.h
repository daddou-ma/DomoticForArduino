#ifndef Commands_H
#define Commands_H

#include <Arduino.h>

enum CommandEnum {
  getStats, setStats, getPin, setPin, setTimer, NullCommand
};

class Commands {
  public:
    static CommandEnum getEnum(String command);
};

#endif
