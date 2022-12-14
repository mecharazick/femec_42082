#include <SPI.h>
#include <Arduino.h>
#include <Ethernet.h>

int BUTTON_PIN = 2;
long int now = millis();
long int timeout = 10;

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x64, 0x50};
IPAddress local_ip = IPAddress(192, 168, 0, 50);
byte gateway[] = {10, 0, 0, 1};
byte subnet[] = {255, 255, 0, 0};

EthernetServer server = EthernetServer(23);

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Ethernet.begin(mac, local_ip, gateway, subnet);
  server.begin();
}

void loop()
{
  if (now + timeout < millis())
    if (digitalRead(BUTTON_PIN) == HIGH)
    {
      EthernetClient client = server.available();
      if (client = true)
        run();
      now = millis();
    }
}

void run()
{
  server.write(1);
}
