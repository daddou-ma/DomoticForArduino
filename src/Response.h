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
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root  = jsonBuffer.createObject();
      root["status"]    = (int) Config;
      root["arduino"]   = "arduino_uno";
      root["id"]        = Config::id;

      root.printTo(Serial);
    }

    static void success(String msg) {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["status"]    = (int) Success;
      root["req"] = msg;

      root.printTo(Serial);
    }

    static void error(String msg) {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["status"]    = (int) Error;
      root["req"] = msg;

      root.printTo(Serial);
    }

    static void jsonError(String msg) {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["status"]    = (int) JsonError;
      root["req"] = msg;

      root.printTo(Serial);
    }
};

#endif
