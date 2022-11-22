#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

int port 80;

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x64, 0x50} // Endereço MAC específico do SHIELD

// ip
byte ip[] = {192, 168, 1, 245};

// the router's gateway address:
byte gateway[] = {192, 168, 1, 1};

// the subnet:
byte subnet[] = {255, 255, 0, 0};

EthernetServer server = EthernetServer(port);

void setup()
{
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.begin(9600);
}

void loop()
{
}