#include "Arduino.h"
//The setup function is called once at startup of the sketch

int led = 9;

void setup()
{
	pinMode(A0, INPUT);	//�Ƴ��α״� pinmode ������ ���ص� �������.
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	int analogR = analogRead(A0); //0~1023
	Serial.println(analogR);

	analogWrite(led, analogR);
}
