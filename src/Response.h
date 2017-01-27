#ifndef Response_H
#define Response_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Config.h"

enum StatusCode:uint8_t {
  Config = 10,  Success = 20, JsonError = 30, Error = 40
};

class Response {
  public:
    static void requestConfig() {
      StaticJsonBuffer<50> jsonBuffer;

      JsonObject& root  = jsonBuffer.createObject();
      root[F("status")]    = (uint8_t) Config;
      root[F("arduino")]   = F("arduino_uno");
      root[F("id")]        = Config::id;

      root.printTo(Serial);
    }

    static void message(StatusCode code, int request) {
      StaticJsonBuffer<50> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root[F("status")]    = (uint8_t) code;
      root[F("req")] = request;

      root.printTo(Serial);
    }
};

#endif
