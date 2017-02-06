#include "Arduino.h"
int outputpin= 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
	 int sensorValue = analogRead(outputpin);
	 float mVoltage = sensorValue * 5.0/1024.0;
	 float temperatureC = (mVoltage ) * 100.0;
	 Serial.print("1.sensor read value: ");
	 Serial.println(sensorValue);
	 Serial.print("2.sensor m volt    : ");
	 Serial.println(mVoltage);
	 Serial.print("3.degree c         : ");
	 Serial.println(temperatureC);
	 Serial.println();

	 delay(2000);
}
