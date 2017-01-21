#include "Stats.h"

Pin  Stats::pinsArray[COUNT_PIN];
Pin  Stats::tempArray[COUNT_PIN];
bool Stats::pinsStats[COUNT_PIN];
int  Stats::timer = 3;

bool Stats::setStats(JsonObject& json) {
  // TODO : verification of validation of a json

  Stats::timer = json["timer"];
  JsonArray& pins = json["pins"];

  for (unsigned int i = 0; i < pins.size(); i++) {
    Pin pin = Pin(pins[i]["name"], pins[i]["number"], Pin::getPinTypeFromString(pins[i]["type"]));
    tempArray[i] = pin;
  }

  return 0;
}

JsonObject& Stats::getStats() {
  // TODO
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["timer"] = Stats::timer;
  JsonArray& pins = root.createNestedArray("pins");
  for (unsigned int i = 0; i < (sizeof(pinsArray) / sizeof(Pin)); i++) {
    JsonObject& pin = pins.createNestedObject();
    JsonHelper::pinToJson(pinsArray[i]);
  }
  return root;
}

bool Stats::initStats(JsonObject& json) {
  // TODO

  if (JsonHelper::haveTimer(json)) {
    timer = json["timer"];
  }


  JsonArray& pins = json["pins"];

  for (unsigned int i = 0; i < pins.size(); i++) {
    if (JsonHelper::isPin(pins[i]))
    {
      Pin pin = Pin(pins[i]["name"], pins[i]["number"], Pin::getPinTypeFromString(pins[i]["type"]));
      tempArray[i] = pin;
    }
    else {
      return false;
    }
  }

  return true;
}

void Stats::resetStats() {
  for (int i = 0; i < COUNT_PIN; i++) {

  }
}
