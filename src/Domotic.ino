#include <Arduino.h>

#define ARDUINOJSON_ENABLE_ARDUINO_STREAM 0

#include "JsonHelper.h"
#include "Commands.h"
#include "./Pin/Pin.h"
#include "Config.h"


const String ID       = "HH10225";
bool connected  = false;

int 		i = 0;
//Pin 		pins[PIN_COUNT];

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while(!Serial) {}

  while(!connected) {
    Serial.print(ID);
    while (Serial.available() > 0) {
        delay(2500);
        String a = Serial.readStringUntil('\n');
        connected = true;
        Serial.println("READ CHAR i : " + a);
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
    String text = "";
    while(Serial.available() > 0) {
      char character = Serial.read();
      text.concat(character);
    }

    JsonObject& json = JsonHelper::getJson(text);

    Serial.println();
    Serial.println("Text : " + text);
    Serial.println();
    //json.printTo(Serial);

    /*if (!json.success()) {
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
    }*/
  }

  Serial.println("Waiting");
  delay(1000);
  /*digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  i = (i < TIMER) ? i+1:0;
  */
}