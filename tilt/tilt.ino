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
    //기울음 = 0, 기울면 끄고
    digitalWrite(led,LOW);
  }else{
	//안기울음 = 1, 안기울면 킨다.
    digitalWrite(led,HIGH);
  }
  last_tilt_status = cur_tilt_status;

}

boolean debounce(boolean last)
{
    boolean current=digitalRead(tilt); //현재 상태를 확인
    if(last!=current) //이전 상태와 현재 상태가 다름
    {
        delay(5); //5ms 동안 기다림
        current=digitalRead(tilt); //current에 현재 상태를 저장
    }
    return current; //current 변수값을 반환
}


