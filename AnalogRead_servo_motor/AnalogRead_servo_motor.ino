#include "Arduino.h"
#include <Servo.h>
Servo myservo;
int i=0;
int potpin=A0;   //���������Է���
int potval=0;    //���������Է°�
void setup() {
  pinMode(A0,INPUT);
  // put your setup code here, to run once:
  myservo.attach(5);// 9���ɿ� ������ ��ģ��
  Serial.begin(9600);
}

void loop() {
  potval=analogRead(potpin);//0~1023
  int degree = map(potval,0,1023,0,180);
//  myservo.write(degree);
  Serial.println(degree);
//  delay(15);

  myservo.write(180);
  delay(200);
  int randd = random();
  if(randd < 0){
	  randd = randd * -1;
  }
  randd = randd%30;
  Serial.println(randd);
  int rand = (int) randd;
  for(i=0;i<=180;i=i+(rand%3)+3){
    myservo.write(i);
    delay(rand);
  }

  if(rand%2 == 0){
	  for(i=180;i>=0;i=i-(rand%3)+3){
		myservo.write(i);
		delay(rand);
	  }
  }


}










