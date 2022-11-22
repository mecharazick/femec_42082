#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <XBee.h>

int slavePin = 4;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
}

void handleButtonPress(int buttonpin)
{
}
