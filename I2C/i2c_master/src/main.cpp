// Wire Master Writer by Nicholas Zambetti http://www.zambetti.com
#include <Arduino.h>
#include <Wire.h>

void handleButtonPress(int buttonId);
void ledOn(void);
void ledOff(void);

int buttonOnpin = 8;
int buttonOfpin = 9;

int on = 1;
int off = 2;

void setup()
{
  pinMode(buttonOnpin, INPUT_PULLUP);
  pinMode(buttonOfpin, INPUT_PULLUP);
  Wire.begin(); // inicia i2c bus (endereço opc para mestre)
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(buttonOnpin) == HIGH)
  {
    Serial.println(buttonOnpin);
    handleButtonPress(buttonOnpin);
  }
  else if (digitalRead(buttonOfpin) == HIGH)
  {
    Serial.println(buttonOfpin);
    handleButtonPress(buttonOfpin);
  } 
  delay(100);
}

void handleButtonPress(int buttonpin)
{
  if (buttonpin == 8)
  {
    ledOn();
  }
  else if (buttonpin == 9)
  {
    ledOff();
  }
}

void ledOn()
{
  Serial.println("on");
  Wire.beginTransmission(4);
  Wire.write(on);
  Wire.endTransmission();
}

void ledOff()
{
  Serial.println("off");
  Wire.beginTransmission(4);
  Wire.write(off);
  Wire.endTransmission();
}
