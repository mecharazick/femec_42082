#include <Arduino.h>
#include <XBee.h>

XBee xbee = XBee();

void setup() {
  Serial.begin(9600);
  xbee.setSerial(Serial);
}

void loop() {
}