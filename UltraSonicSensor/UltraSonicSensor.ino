#include "Arduino.h"


//�����(trig)�� �Է���(echo) ���� ����, �ٸ� ���� �����ص� ��.
int trigPin = 2;
int echoPin = 3;

//�ø��� �ӵ�����, trigPin�� ���, echoPin�� �Է����� ����
void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
}

//�����ĸ� ������. �� ������ echo�� HIGH(��ȣ�ޱ�) ���·� ���
void loop() {
	float duration, distance;
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// echoPin �� HIGH�� ������ �ð��� ���� �Ѵ�.
	duration = pulseIn(echoPin, HIGH);
	// HIGH ���� �� �ð�(�����İ� ���´ٰ� �ٽ� ���� �ð�)�� ������ �Ÿ��� ��� �Ѵ�.
	// 340�� �ʴ� ������(�Ҹ�)�� �ӵ�, 10000�� �и������带 �������, �պ��Ÿ��̹Ƿ� 2�� �����ش�.
	distance = ((float) (340 * duration) / 10000)/ 2;

	//�ø������Ϳ� Echo�� HIGH�� �ð� �� �Ÿ��� ǥ�����ش�.
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
