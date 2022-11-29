#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <XBee.h>
//init varirables
int step = 0;
int seq[] = {1, 2, 0, 1, 2};
int slavePin = 4;
int maxMessageLength = 1;
bool seqRunning = false;

void receiveSlave(int receivedBytes);
int requestSlave();

void setup()
{
  Wire.begin();
  Wire.onReceive(receiveSlave);
  Serial.begin(9600);
}

void loop()
{
  int pos = requestSlave();
}
//i2c communication (comms ard2)
void receiveSlave(int receivedBytes)
{
  if (Wire.available() && !seqRunning)
  {
    int message = Wire.read();
    if (message)
      seqRunning = true;
  }
}

int requestSlave()
{
  Wire.requestFrom(slavePin, maxMessageLength);
}