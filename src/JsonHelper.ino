
#include "JsonHelper.h"

JsonObject& JsonHelper::getJson(String text) {

  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(text);

  return root;
}

Pin JsonHelper::jsonToPin(JsonObject& json) {
  uint8_t number    = json[F("number")];
  uint8_t type      = json[F("type")];

  switch ((PinType) type) {
    case DIGITAL_OUTPUT:
    {
      uint8_t value = json[F("value")];
      DigitalOutputPin pin = DigitalOutputPin(number);
      pin.setValue(value);
      return pin;
    }
    break;
    case ANALOG_INPUT:
    {
      uint8_t  analogType = (uint8_t) json[F("analog_type")];
      AnalogInputPin pin = AnalogInputPin(number, (AnalogInputType) analogType);
      return pin;
    }
    break;
    case DHT_INPUT:
    {
      DigitalDHTPin pin = DigitalDHTPin(number);
      return pin;
    }
    break;
    default:
      // May be it cause problem
    break;
  }
}

JsonObject& JsonHelper::pinToJson(Pin pin) {
  // TODO
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root[F("number")]  = pin.number;
  root[F("type")]    = (uint8_t)pin.type;

  switch (pin.type) {
    case DIGITAL_OUTPUT:
    {
      DigitalOutputPin pin = (DigitalOutputPin)pin;
      root[F("value")]   = pin.getValue();
    }
    break;
    case ANALOG_INPUT:
    {
      AnalogInputPin pin = (AnalogInputPin)pin;
      root[F("analog_type")]   = pin.getAnalogType();
    }
    break;
    case DHT_INPUT:
    {
      DigitalDHTPin pin = (DigitalDHTPin)pin;
      root[F("temperature")]   = pin.getValue().temperature;
      root[F("humidity")]      = pin.getValue().humidity;
    }
    break;
  }

  return root;
}

bool JsonHelper::isValidInitStatsCommand(JsonObject& json) {
  if(!haveStats(json))
  {
    return false;
  }

  JsonObject& stats = json[F("stats")];

  if(!haveTimer(stats)) {
    return false;
  }

  if(!havePinArray(stats)) {
    return false;
  }

  return true;
}

bool JsonHelper::haveCommand(JsonObject& json){
  if (json.containsKey(F("command"))) {
    return true;
  }
  return false;
}

bool JsonHelper::isPin(JsonObject& json){

  // Verify Basic Pin
  if (!json.containsKey(F("number")) || !json.containsKey(F("type"))) {
    return false;
  }

  // Verify Pin according to his type
  uint8_t type = (uint8_t) json[F("type")];
  switch ((PinType) type) {
    case DIGITAL_OUTPUT:
      // Do Nothing (Return true)
    break;
    case ANALOG_INPUT:
      if (!json.containsKey(F("analog_type"))) {
        return false;
      }
    break;
    case DHT_INPUT:
      if (!json.containsKey(F("temperature")) || !json.containsKey(F("humidity"))) {
        return false;
      }
    break;
    default:
      return false;
    break;
  }
  return true;
}

bool JsonHelper::havePinArray(JsonObject& json){

  if (!json.containsKey(F("pins"))) {
    return false;
  }

  JsonArray& pins = json.createNestedArray(F("pins"));
  if (pins.size() > COUNT_PIN) {
    return false;
  }

  for (unsigned int i = 0; i < pins.size(); i++) {
    if (!JsonHelper::isPin(pins[i]))
    {
      return false;
    }
  }

  return true;
}

bool JsonHelper::haveStats(JsonObject& json){

  if (json.containsKey(F("stats"))) {
    return true;
  }
  return false;
}

bool JsonHelper::haveTimer(JsonObject& json){
  if (json.containsKey(F("timer"))) {
    return true;
  }
  return false;
}
