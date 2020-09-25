#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const uint8_t PIN_1 = D5;
const uint8_t PIN_2 = D6;
const uint8_t PIN_3 = D7;
const uint8_t PIN_4 = D8;
const int DELAY = 15;
const int REVOLUTION = 2048;

void sequence(bool a, bool b, bool c, bool d)
{
  digitalWrite(PIN_1, a);
  digitalWrite(PIN_2, b);
  digitalWrite(PIN_3, c);
  digitalWrite(PIN_4, d);
  delay(DELAY);
}

void goRight()
{
  for(int j = 0; j<REVOLUTION; j++)
  {
    sequence(HIGH, HIGH, LOW, LOW);
    sequence(HIGH, LOW, LOW, HIGH);
    sequence(LOW, LOW, HIGH, HIGH);
    sequence(LOW, HIGH, HIGH, LOW);
  }
  sequence(HIGH, HIGH, LOW, LOW);
}


void goLeft()
{
  for(int i = 0; i<REVOLUTION; i++)
  {
    sequence(HIGH, HIGH, LOW, LOW);
    sequence(LOW, HIGH, HIGH, LOW);
    sequence(LOW, LOW, HIGH, HIGH);
    sequence(HIGH, LOW, LOW, HIGH);
  }
  sequence(HIGH, HIGH, LOW, LOW);
}

void setup()
{
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
}

void loop()
{
  goRight();
  delay(1000);
  goLeft();
  delay(1000);
}