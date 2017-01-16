#ifndef JsonHelper_H
#define JsonHelper_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "./Pin/Pin.h"

class JsonHelper {

  public:

    static JsonObject& getJson(String text);

    static Pin jsonToPin(String text);

    static bool haveCommand(JsonObject& json);

    static bool haveStats(JsonObject& json);

    static bool haveTimer(JsonObject& json);

};

#endif // JsonHelper_H
