#include "Arduino.h"

int colorMode = 0;
// the setup routine runs once when you press reset:
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  /*
  공통애노드방식 RGB LED
  */
  /*RED
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(100);*/
  //setDigitalColor(LOW,HIGH,HIGH);
  /*GREEN
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(100);*/

  /*BLUE
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(100);*/


  /*
  RED
  analogWrite(9,0);
  analogWrite(10,255);
  analogWrite(11,255);
  */

  /*
  RED/2 + GREEN/2

  analogWrite(9,127);
  analogWrite(10,127);
  analogWrite(11,255);
  delay(100);*/

	colorMode++;
  setColorMode((colorMode%7)+1);
  delay(100);


//  analogWrite(9,56);
//  analogWrite(10,255);
//  analogWrite(11,255);


  //setColorMode(5);
  //delay(1000);

}
void setAnalogColor(int red,int green,int blue){
	analogWrite(9,red);
    analogWrite(10,green);
    analogWrite(11,blue);
}
void setDigitalColor(int red,int green,int blue){
	digitalWrite(9,red);
    digitalWrite(10,green);
    digitalWrite(11,blue);
}

void setColorMode(int mode){
  switch(mode){
  	case 1:
    	setAnalogColor(255,0,0);
    	break;
    case 2:
    	setAnalogColor(255,94,0);
    	break;
    case 3:
    	setAnalogColor(255,187,0);
    	break;
    case 4:
    	setAnalogColor(0,255,0);
    	break;
    case 5:
    	setAnalogColor(0,0,255);
    	break;
    case 6:
    	setAnalogColor(5,0,153);
    	break;
    case 7:
    	setAnalogColor(95,0,255);
    	break;
  }



}






















