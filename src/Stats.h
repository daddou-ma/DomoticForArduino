#ifndef Stats_H
#define Stats_H

#include <Arduino.h>
#include "Config.h"
#include "JsonHelper.h"

class Stats {

public:
  static Pin  pinsArray[COUNT_PIN-START_PIN];
  static uint8_t  timer;

  static JsonObject& getStats();

  static bool initStats(JsonObject& json);

};

#endif
