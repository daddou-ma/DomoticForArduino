#ifndef Response_H
#define Response_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Config.h"

enum StatusCode:int {
  Config = 100,  Success = 200, JsonError = 300, Error = 400
};

class Response {
  public:
    static void requestConfig() {
      StaticJsonBuffer<50> jsonBuffer;

      JsonObject& root  = jsonBuffer.createObject();
      root["status"]    = (uint8_t) Config;
      root["arduino"]   = "arduino_uno";
      root["id"]        = Config::id;

      root.printTo(Serial);
    }

    static void message(StatusCode code, int request) {
      StaticJsonBuffer<50> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["status"]    = (uint8_t) code;
      root["req"] = request;

      root.printTo(Serial);
    }
};

#endif
