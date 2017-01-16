#include <Arduino.h>

#include <ArduinoJson.h>
#include "JsonHelper.h"
#include "./Pin/Pin.h"

JsonObject& JsonHelper::getJson(String text) {

  //Serial.println(text + "ALLOWED");
  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(text.c_str());

  return root;
}

Pin JsonHelper::jsonToPin(String text) {
  // TODO
  Pin pin = Pin("test Pin", 2, DIGITAL_OUTPUT);
  return pin;
}

bool JsonHelper::haveCommand(JsonObject& json){
  // TODO
  if (json.containsKey("Command")) {
    return 0;
  }
  return 0;
}

bool JsonHelper::haveStats(JsonObject& json){
  // TODO
  if (json.containsKey("Stats")) {
    return 0;
  }
  return 0;
}

bool JsonHelper::haveTimer(JsonObject& json){
  // TODO
  if (json.containsKey("Timer")) {
    return 0;
  }
  return 0;
}
