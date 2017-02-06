#include "Arduino.h"


//�����(trig)�� �Է���(echo) ���� ����, �ٸ� ���� �����ص� ��.
int trigPin = 2;
int echoPin = 3;

//�ø��� �ӵ�����, trigPin�� ���, echoPin�� �Է����� ����
void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

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



	int cdistance=constrain(distance,10,50);
	Serial.print("\ncdIstance:");
	Serial.print(cdistance);
	Serial.println("cm\n");
	int delayDuration = map(cdistance,10,50,0,700);

	tone(8,200,50);
	delay(delayDuration);

	//noTone(8);


}
