#ifndef Commands_H
#define Commands_H

#include <Arduino.h>
#include "ArduinoJson.h"

/*
  CommandEnum XY
  Y : (0: notUsed) (1: Stats) (2: Pin) (3: Timer)
  Y : (0: init) (1: get) (2: set)
*/

enum CommandEnum:int {
  initStats = 10, setPin = 22, setTimer = 32, NullCommand = -1
};

class Commands {
  public:
    static void execCommand(CommandEnum command, JsonObject& json);
    static void initStats(JsonObject& json);
};

#endif
