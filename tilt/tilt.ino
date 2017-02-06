#include "Arduino.h"

int led = 2;
int tilt= 11;
boolean cur_tilt_status = false;
boolean last_tilt_status = false;

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(tilt,INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
	cur_tilt_status= debounce(last_tilt_status);
  	int tiltValue = digitalRead(tilt);
  	Serial.println(tiltValue);
  if(tiltValue==LOW){	//low = 0
    //����� = 0, ���� ����
    digitalWrite(led,LOW);
  }else{
	//�ȱ���� = 1, �ȱ��� Ų��.
    digitalWrite(led,HIGH);
  }
  last_tilt_status = cur_tilt_status;

}

boolean debounce(boolean last)
{
    boolean current=digitalRead(tilt); //���� ���¸� Ȯ��
    if(last!=current) //���� ���¿� ���� ���°� �ٸ�
    {
        delay(5); //5ms ���� ��ٸ�
        current=digitalRead(tilt); //current�� ���� ���¸� ����
    }
    return current; //current �������� ��ȯ
}


