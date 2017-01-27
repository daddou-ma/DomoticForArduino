#define ARDUINOJSON_ENABLE_ARDUINO_STREAM 0

#include <Arduino.h>
#include "./Pin/Pin.ino" // Keep It [Error : linker undefined reference to Pin::Pin]
#include "JsonHelper.h"
#include "Commands.h"
#include "Config.h"
#include "Response.h"
#include "Stats.h"

bool connected  = false;

uint8_t 		i = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while(!Serial) {}

  while(!connected) {
    Response::requestConfig();

    // Waiting For Configuration From Serial Port
    if (Serial.available() > 0) {

      char text[15];
      int j = 0;
      while(Serial.available() > 0) {
        text[j] = (char) Serial.read();
        j++;
      }

      JsonObject& json = JsonHelper::getJson(text);

      if (!json.success()) {
        // TODO : Error Message
        Response::message(StatusCode::JsonError, 0);
      }
      else {
        int command = json[F("command")];
        if (JsonHelper::isValidInitStatsCommand(json)) {
          Commands::execCommand((CommandEnum)command, json);
          connected = true;
        }
        else {
          Response::message(StatusCode::Error, 0);
        }
      }
    }
    delay(500);
  }
}

// the loop routine runs over and over again forever:
void loop() {

  if (Serial.available() > 0) {
    String text = Serial.readString();

    JsonObject& json = JsonHelper::getJson(text);

    if (!json.success()) {
      // TODO : Error Message
      //Serial.println("NOT JSON");
      return;
    }
    int command = json[F("command")];
    switch((CommandEnum)command) {
      case initStats:
        // TODO : Set Stats
        break;
      case setPin:
        // TODO : Set Pin
        break;
      case setTimer:
        // TODO : Set Pin
        break;
      case NullCommand:
      default:
        // TODO : Error Message
        break;
    }
  }

  if(i % Stats::timer == 0)
  {
    JsonObject& stats = Stats::getStats();
    stats.printTo(Serial);
  }

  i++;

  delay(1000);
}
