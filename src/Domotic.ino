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
//Pin 		pins[PIN_COUNT];

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while(!Serial) {}

  while(!connected) {
    Response::requestConfig();

    // Waiting For Configuration From Serial Port
    while (Serial.available() > 0) {

      String text = Serial.readStrin

      JsonObject& json = JsonHelper::getJson(text);

      if (!json.success()) {
        // TODO : Error Message
        Response::message(StatusCode::JsonError, 0);
      }
      else {
        int command = json["command"];
        Commands::execCommand((CommandEnum)command, json);
        connected = true;
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
    int command = json["command"];
    switch((CommandEnum)command) {
      case initStats:
        // TODO : Set Stats
        //Serial.println("Init Stats : Command Received");
        break;
      case setPin:
        // TODO : Set Pin
        //Serial.println("Set Pin : Command Received");
        break;
      case setTimer:
        // TODO : Set Pin
        //Serial.println("Set Timer : Command Received");
        break;
      case NullCommand:
        // TODO : Error Message
        //Serial.println("Unknown Command");
        break;
      default:
        // TODO : Error Message
        //Serial.println("Unknown Command");
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
