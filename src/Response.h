#ifndef Response_H
#define Response_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Config.h"

class Response {
  public:
    static void requestConfig() {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root  = jsonBuffer.createObject();
      root["type"]      = "request";
      root["id"]        = Config::id;

      root.printTo(Serial);
    }

    static void success(String msg) {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["type"] = "success";
      root["msg"] = msg;

      root.printTo(Serial);
    }

    static void error(String msg) {
      StaticJsonBuffer<100> jsonBuffer;

      JsonObject& root = jsonBuffer.createObject();
      root["type"] = "error";
      root["msg"] = msg;

      root.printTo(Serial);
    }
};

#endif
