#ifndef Stats_H
#define Stats_H

#include <Arduino.h>
#include "Config.h"
#include "JsonHelper.h"

class Stats {

public:
  static Pin  pinsArray[COUNT_PIN];
  static Pin  tempArray[COUNT_PIN];
  static bool pinsStats[COUNT_PIN];
  static int  timer;

  static bool setStats(JsonObject& json);

  static JsonObject& getStats();

  static bool initStats(JsonObject& json);

  static void resetStats();
};

#endif
