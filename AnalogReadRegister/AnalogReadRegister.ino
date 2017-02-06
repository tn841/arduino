#include "Arduino.h"
//The setup function is called once at startup of the sketch

int led = 9;

void setup()
{
	pinMode(A0, INPUT);	//아날로그는 pinmode 설정을 안해도 상관없다.
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	int analogR = analogRead(A0); //0~1023
	Serial.println(analogR);

	analogWrite(led, analogR);
}
