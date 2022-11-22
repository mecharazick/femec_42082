#include <Arduino.h>
#include <Wire.h>

void receiveEvent(int howMany);

int LED = 5;

int on = 1;
int off = 2;
void setup()
{
  Wire.begin(4);
  
  Wire.onReceive(receiveEvent);
  
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  delay(100);
}

void receiveEvent(int howMany) // define função receiveEvent
{
  int state;
  if(Wire.available()){
    state = Wire.read();
    if(state == 1){
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }
  }
}