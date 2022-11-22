#include <SPI.h>
#include <Arduino.h>
#include <Ethernet.h>
#include <Wire.h>

int A0_PIN = 3;
int A1_PIN = 4;

int piston_course = 0;

int i2c_analog_pin = 2;
bool start = false;

IPAddress local_ip = IPAddress(192, 168, 0, 44);
IPAddress remote_ip = IPAddress(192, 168, 0, 50);
uint8_t remote_port = 23;
byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x64, 0x44};

EthernetClient client;

void connectToServer();
int checkConnection();
int readServer();
void i2cReceive(int received);

void setup()
{
  pinMode(A0_PIN, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);
  
  Wire.begin(4);
  Wire.onReceive(i2cReceive);

  Ethernet.begin(mac, local_ip);
  connectToServer();
}

void loop()
{
  readServer();
  int serverStatus = checkConnection();
  if (serverStatus == -1)
    connectToServer();
}

void i2cReceive(int received)
{
  
}

void connectToServer()
{
  Serial.println("Connecting...");
  if (client.connect(remote_ip, remote_port))
  {
    Serial.println("Connected");
  }
  else
  {
    Serial.println("Connection Failed");
  }
}

int checkConnection()
{
  if (!client.connected())
  {
    Serial.println();
    Serial.println("Disconnected.");
    client.stop();
    return -1;
  }
  return 1;
}

int readServer()
{
  if (client.available())
  {
    bool c = client.read();
    if (c)
      return 1;
    else
      return -1;
  }
}