#include "Arduino.h"
//The setup function is called once at startup of the sketch
int pin = 8;
boolean flag = false;
boolean cur = 0;
boolean last = 0;

boolean debounce(boolean last);

void setup()
{
// Add your initialization code here
	pinMode(pin, INPUT);
	Serial.begin(9600);
}

// The loop function is called in an endless loop
void loop()
{
	cur = debounce(last);
	if(last == 0 && cur == 1){
		flag = !flag;
	}
//Add your repeated code here
	int btn_read = digitalRead(pin);	//0 or 1
	Serial.print(btn_read);
	Serial.print(flag);
	Serial.println();


//	if( (btn_read == 1) && (flag == false) ){
//		flag = true;
//		delay(100);
//	}else if( (btn_read == 1) && (flag == true) ){
//		flag = false;
//		delay(100);
//	}


	if(flag){
		digitalWrite(13, HIGH);
	}else{
		digitalWrite(13, LOW);
	}


}

boolean debounce(boolean last){
	boolean current = digitalRead(pin);
	if(last != current){
		delay(5);
		current = digitalRead(pin);
	}
	return current;
}
