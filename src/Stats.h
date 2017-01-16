#ifndef Stats_H
#define Stats_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "./Pin/Pin.h"
#include "Config.h"

class Stats {

  static Pin  pinsArray[COUNT_PIN];
  static Pin  tempArray[COUNT_PIN];
  static bool pinsStats[COUNT_PIN];
  static int  timer;

  static bool setStats(JsonObject& json) {
    // TODO : verification of validation of a json

    timer = json["timer"];
    JsonArray& pins = json["pins"];

    for (int i = 0; i < pins.size(); i++) {
      Pin pin = Pin(pins[i]["name"], pins[i]["number"],pins[i]["Type"]);
      tempArray[i] = pin;
    }

    return 0;
  }

  static JsonObject& getStats() {
    // TODO

  }

  static void resetStats() {
    for (int i = 0; i < COUNT_PIN; i++) {

    }
  }
};

#endif
