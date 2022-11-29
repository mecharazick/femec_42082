#include <SPI.h>
#include <Arduino.h>
#include <Ethernet.h>
#include <Wire.h>
// Init Variables
int A0_PIN = 3;
int A1_PIN = 4;

int i2c_analog_pin = 2;
bool running = false;

byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x64, 0x44};
IPAddress local_ip = IPAddress(192, 168, 0, 44);
IPAddress remote_ip = IPAddress(192, 168, 0, 50);
uint8_t remote_port = 23;

EthernetClient client;
// Declaring functions
void connectToServer();
int connectionStatus();
int checkStartCommand();
void readMaster(int received);
void respondMaster();
int getTrackState();
void run();
void stop();

void setup()
{
  pinMode(A0_PIN, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);

  Wire.begin(4);
  Wire.onRequest(respondMaster);
  Wire.onReceive(readMaster);

  Ethernet.begin(mac, local_ip);
  connectToServer();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (!running)
  {
    if (!connectionStatus())
      connectToServer();
    else if (checkStartCommand())
      start();
  }
}

// Execute Sequence Control Logic
void start()
{
  running = true;
}

void stop()
{
  running = false;
}

int getTrackState()
{
  if (digitalRead(A0_PIN == HIGH))
  {
    return 1;
  }
  else if (digitalRead(A1_PIN) == LOW)
  {
    return 2;
  }
}
// I2C connection functions (Comms Ard3)
void readMaster(int received)
{
}

void respondMaster()
{
  int trackState = getTrackState();
  Wire.write(trackState);
}

// Ethernet connection functions (Comms Ard1)
void connectToServer()
{
  Serial.println("Connecting...");
  if (client.connect(remote_ip, remote_port))
  {
    Serial.println("Connected to server");
  }
  else
  {
    Serial.println("Connection Failed");
  }
}

int connectionStatus()
{
  if (!client.connected())
  {
    Serial.println();
    Serial.println("Disconnected.");
    client.stop();
    return 0;
  }
  return 1;
}

int checkStartCommand()
{
  if (client.available())
  {
    bool c = client.read();
    return c;
  }
}