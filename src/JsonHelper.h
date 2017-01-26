#define ARDUINOJSON_ENABLE_ARDUINO_STREAM 0
#define ARDUINOJSON_ENABLE_PROGMEM 1

#ifndef JsonHelper_H
#define JsonHelper_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "./Pin/Pin.h"
#include "./Pin/AnalogInputPin/AnalogInputPin.h"
#include "./Pin/DigitalOutputPin/DigitalOutputPin.h"
#include "./Pin/DigitalDHTPin/DigitalDHTPin.h"

class JsonHelper {

  public:

    static JsonObject& getJson(String text);

    static Pin  jsonToPin(JsonObject& json);

    static JsonObject& pinToJson(Pin pin);

    static bool isValidInitStatsCommand(JsonObject& json);

    static bool isPin(JsonObject& json);

    static bool havePinArray(JsonObject& json);

    static bool haveCommand(JsonObject& json);

    static bool haveStats(JsonObject& json);

    static bool haveTimer(JsonObject& json);

};

#endif // JsonHelper_H
