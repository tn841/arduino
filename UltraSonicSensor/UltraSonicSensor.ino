#include "Arduino.h"


//출력핀(trig)과 입력핀(echo) 연결 설정, 다른 핀을 연결해도 됨.
int trigPin = 2;
int echoPin = 3;

//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
}

//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop() {
	float duration, distance;
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// echoPin 이 HIGH를 유지한 시간을 저장 한다.
	duration = pulseIn(echoPin, HIGH);
	// HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
	// 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
	distance = ((float) (340 * duration) / 10000)/ 2;

	//시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시해준다.
	Serial.print("duration:");
	Serial.print(duration);
	Serial.print("\ndistance:");
	Serial.print(distance);
	Serial.println("cm\n");
	delay(500);

/*
	int cdistance=constrain(distance,0,30);
	Serial.print("\nCDIstance:");
	Serial.print(cdistance);
	Serial.println("cm\n");


	int ledData=map(cdistance,0,20,0,255);
	int ledDuration=map(cdistance,0,20,0,700);

	analogWrite(9, ledData);
	analogWrite(10,255);
	analogWrite(11,255);
	delay(ledDuration);

	analogWrite(9, 255);
	analogWrite(10,255);
	analogWrite(11,255);
	delay(ledDuration);

	tone(8,10,50);
	delay(ledDuration);
	//noTone(8);
*/


}
