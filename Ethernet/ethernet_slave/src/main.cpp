#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac = {0x90, 0xA2, 0xDA, 0x00, 0x64, 0x50} // Endereço MAC específico do SHIELD

IPAdress ip(192, 168, 1, 246);

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
}

void loop()
{
}