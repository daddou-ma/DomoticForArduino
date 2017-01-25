#define ARDUINOJSON_ENABLE_ARDUINO_STREAM 0

#include <Arduino.h>
#include "./Pin/Pin.ino" // Keep It [Error : linker undefined reference to Pin::Pin]
#include "JsonHelper.h"
#include "Commands.h"
#include "Config.h"
#include "Response.h"
#include "Stats.h"

bool connected  = false;

int 		i = 0;
//Pin 		pins[PIN_COUNT];

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while(!Serial) {}

  while(!connected) {
    Response::requestConfig();

    // Waiting For Configuration From Serial Port
    while (Serial.available() > 0) {
      String text = Serial.readString();

      JsonObject& json = JsonHelper::getJson(text);

      if (!json.success()) {
        // TODO : Error Message
        Response::error("UnValid Config Msg");
      }
      else {
        Response::success("Moved to Loop");
        connected = true;
      }
    }
    delay(500);
  }

  /*
  // initialize the digital pin as an output.
  for (int i = 0; i <= PIN_COUNT; i++) {
    pinMode(pins[i].number, pins[i].type);
    Serial.write("PIN Set : ");
  }
  // initialize the digital pin as an output.
  for (int i = 0; i <= PIN_COUNT; i++) {
    pinMode(pins[i].number, pins[i].type);
    Serial.write("PIN Set : ");
  }
  */
}

// the loop routine runs over and over again forever:
void loop() {

  // Setting the values of input pin objects
  /*for (int i = 0; i <= PIN_COUNT; i++) {
    if(pins[i].type == INPUT) {
      //pins[i].value = digitalRead(pins[i].number);
      pins[i].value = digitalRead(pins[i].number);
    }
  }*/

  if (Serial.available() > 0) {
    String text = Serial.readString();

    JsonObject& json = JsonHelper::getJson(text);


    if (!json.success()) {
      // TODO : Error Message
      Serial.println("NOT JSON");
      return;
    }
    String command = json["command"];
    switch(Commands::getEnum(command)) {
      case getStats:
        // TODO : Return Of Stats
        Serial.println("Get Stats : Command Received");
        break;
      case setStats:
        // TODO : Set Stats
        Serial.println("Set Stats : Command Received");
        break;
      case getPin:
        // TODO : Set Pin
        Serial.println("Get Pin : Command Received");
        break;
      case setPin:
        // TODO : Set Pin
        Serial.println("Set Pin : Command Received");
        break;
      case setTimer:
        // TODO : Set Pin
        Serial.println("Set Timer : Command Received");
        break;
      case NullCommand:
        // TODO : Error Message
        Serial.println("Unknown Command");
        break;
      default:
        // TODO : Error Message
        Serial.println("Unknown Command");
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
