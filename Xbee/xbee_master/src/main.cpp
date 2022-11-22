#include <Arduino.h>
#include <XBee.h>

XBee xbee = XBee();

uint8_t payload[] = {0, 0};

void setup()
{
  Serial.begin(9600);
  xbee.setSerial(Serial);
}

void loop()
{
  // put your main code here, to run repeatedly:
}