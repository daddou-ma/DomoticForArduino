#include "Stats.h"

Pin  Stats::pinsArray[COUNT_PIN] = {  Pin(0 , DIGITAL_OUTPUT),
  Pin(1,    DIGITAL_OUTPUT),Pin(2,    DIGITAL_OUTPUT),Pin(3 ,   DIGITAL_OUTPUT),
  Pin(4,    DIGITAL_OUTPUT),Pin(5,    DIGITAL_OUTPUT),Pin(6 ,   DIGITAL_OUTPUT),
  Pin(7,    DIGITAL_OUTPUT),Pin(8,    DIGITAL_OUTPUT),Pin(9 ,   DIGITAL_OUTPUT),
  Pin(10,   DIGITAL_OUTPUT),Pin(11,   DIGITAL_OUTPUT),Pin(12,   DIGITAL_OUTPUT),
  Pin(13,   DIGITAL_OUTPUT),Pin(0xA0, DIGITAL_OUTPUT),Pin(0xA1, DIGITAL_OUTPUT),
  Pin(0xA2, DIGITAL_OUTPUT),Pin(0xA3, DIGITAL_OUTPUT),Pin(0xA4, DIGITAL_OUTPUT),
  Pin(0xA5, DIGITAL_OUTPUT)
};

bool Stats::pinsStats[COUNT_PIN];
int  Stats::timer = 3;

JsonObject& Stats::getStats() {
  // TODO
  StaticJsonBuffer<1024> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["timer"] = Stats::timer;
  JsonArray& pins = root.createNestedArray("pins");
  for (unsigned int i = 0; i < 20; i++) {
    if(Config::getPinTypeByNumber(pinsArray[i].number) != RESERVED_PIN) {
      JsonObject& pin = pins.createNestedObject();
      pin["pin"] = pinsArray[i].number;
      pin["type"] = (int)pinsArray[i].type;
      pin["value"] = pinsArray[i].value;
    }
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
      int number = json["number"];
      int type   = json["type"];
      Pin pin = Pin(number, (PinType)type);
    }
    else {
      return false;
    }
  }

  return true;
}
