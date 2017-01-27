#include "Stats.h"

Pin  Stats::pinsArray[COUNT_PIN-START_PIN] = {
  Pin(2,    DIGITAL_OUTPUT), Pin(3 ,   DIGITAL_OUTPUT),
  Pin(4,    DIGITAL_OUTPUT),Pin(5,    DIGITAL_OUTPUT),Pin(6 ,   DIGITAL_OUTPUT),
  Pin(7,    DIGITAL_OUTPUT),Pin(8,    DIGITAL_OUTPUT),Pin(9 ,   DIGITAL_OUTPUT),
  Pin(10,   DIGITAL_OUTPUT),Pin(11,   DIGITAL_OUTPUT),Pin(12,   DIGITAL_OUTPUT),
  Pin(13,   DIGITAL_OUTPUT),Pin(0xA0, DIGITAL_OUTPUT),Pin(0xA1, DIGITAL_OUTPUT),
  Pin(0xA2, DIGITAL_OUTPUT),Pin(0xA3, DIGITAL_OUTPUT),Pin(0xA4, DIGITAL_OUTPUT),
  Pin(0xA5, DIGITAL_OUTPUT)
};

uint8_t  Stats::timer = 3;

JsonObject& Stats::getStats() {
  // TODO
  StaticJsonBuffer<1024> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root[F("timer")] = Stats::timer;
  JsonArray& pins = root.createNestedArray(F("pins"));
  for (unsigned int i = 0; i < 20; i++) {
    if(Config::getPinTypeByNumber(pinsArray[i].number) != RESERVED_PIN) {
      JsonObject& pin = pins.createNestedObject();
      pin[F("pin")] = pinsArray[i].number;
      pin[F("type")] = (uint8_t)pinsArray[i].type;
      pin[F("value")] = pinsArray[i].value;
    }
  }
  return root;
}

bool Stats::initStats(JsonObject& json) {
  // TODO

  if (JsonHelper::haveTimer(json)) {
    timer = json[F("timer")];
  }

  JsonArray& pins = json[F("pins")];

  for (unsigned int i = 0; i < pins.size(); i++) {
    if (JsonHelper::isPin(pins[i]))
    {
      uint8_t number = json[F("number")];
      uint8_t type   = json[F("type")];
      Pin pin = Pin(number, (PinType)type);
    }
    else {
      return false;
    }
  }

  return true;
}
