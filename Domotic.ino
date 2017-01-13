#define ARDUINOJSON_ENABLE_ARDUINO_STREAM 0
#include "JsonHelper.h"
#include "DigitalOutputPin.h"
#include "AnalogInputPin.h"
#include "Config.h"


const int ID       = 1;
bool connected  = false;

int 		i = 0;
//Pin 		pins[PIN_COUNT];

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  
  while(!connected) {
    Serial.write(ID);
    if (Serial.available() > 0) {
      connected = true;
    }
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
     /*String a = Serial.readString();
     StaticJsonBuffer<512> jsonBuffer;
     JsonObject& root = jsonBuffer.createObject();
     root["sensor"] = "gps" + a;
     root.printTo(Serial);*/
  }
  
  /*if(i == TIMER) {
    for (int i = 0; i <= PIN_COUNT; i++) {
      if(pins[i].type == OUTPUT) {
        pins[i].value = digitalWrite(pins[i].number);
      }
    }
  }*/
  
  /*digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);    
  i = (i < TIMER) ? i+1:0;
  */
}

