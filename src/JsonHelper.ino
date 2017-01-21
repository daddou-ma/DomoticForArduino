
#include "JsonHelper.h"

JsonObject& JsonHelper::getJson(String text) {

  //Serial.println(text + "ALLOWED");
  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(text);

  return root;
}

Pin JsonHelper::jsonToPin(JsonObject& json) {
  // TODO
  Pin pin = Pin(json["name"], json["number"], Pin::getPinTypeFromString(json["type"]));
  return pin;
}

JsonObject& JsonHelper::pinToJson(Pin pin) {
  // TODO
  StaticJsonBuffer<255> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  //root["name"] = pin.name;
  //root["type"] = pin.type;
  //root["value"] = pin.value;

  return root;
}

bool JsonHelper::haveCommand(JsonObject& json){
  // TODO
  if (json.containsKey("command")) {
    return true;
  }
  return false;
}

bool JsonHelper::isPin(JsonObject& json){
  // TODO
  if (json.containsKey("name") && json.containsKey("number") && json.containsKey("type")) {
    return true;
  }
  return false;
}

bool JsonHelper::haveStats(JsonObject& json){
  // TODO
  if (json.containsKey("stats")) {
    return true;
  }
  return false;
}

bool JsonHelper::haveConfig(JsonObject& json){
  // TODO
  if (json.containsKey("config")) {
    return true;
  }
  return false;
}

bool JsonHelper::haveTimer(JsonObject& json){
  // TODO
  if (json.containsKey("timer")) {
    return true;
  }
  return false;
}
