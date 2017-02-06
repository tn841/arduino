#include "Arduino.h"
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  int light = analogRead(A0);
  int ledLight = map(light,0,1023,255,0);	//	`
  analogWrite(11,ledLight);

  Serial.print("light:");
  Serial.print(light);


  Serial.print(", led strength:");
  Serial.println(ledLight);
  delay(300);
}
