#include "Arduino.h"

int ledPin = 9;

void setup()
{
	pinMode(ledPin, OUTPUT);
}

void loop()
{
	analogWrite(ledPin, 0);
	delay(100);
	analogWrite(ledPin, 50);
	delay(100);
	analogWrite(ledPin, 100);
	delay(100);
	analogWrite(ledPin, 150);
	delay(100);
	analogWrite(ledPin, 200);
	delay(100);
	analogWrite(ledPin, 250);
	delay(100);
}
