#include "myServo.h"

MyServoClass::MyServoClass(void) :pin(6)//Default pin is 6 on which servo is attached
{
	pinMode(pin, OUTPUT);
	penUp();//To put pen in initial position
}

void MyServoClass::penUp(void){
	/*for (int n = 0; n < 100; n++){//It gives the desired PWM signal to turn servo
		digitalWrite(pin, HIGH);
		delayMicroseconds(1700);
		digitalWrite(pin, LOW);
		delayMicroseconds(1700);
	}
	digitalWrite(pin, LOW);//Make output low so that servo may not receive garbage signals*/
}

void MyServoClass::penDown(void){//It gives the desired PWM signal to turn servo
	/*for (int n = 0; n < 100; n++){
		digitalWrite(pin, HIGH);
		delayMicroseconds(1900);//Delay time specifies width of pulse i.e.pulse width modulation
		digitalWrite(pin, LOW);
		delayMicroseconds(1900);
	}
	digitalWrite(pin, LOW);//Make output low so that servo may not receive garbage signals*/
}

void MyServoClass::endServo(void){//This is the ending position of servo after sketching is complete
	for (int n = 0; n < 100; n++){
		digitalWrite(pin, HIGH);
		delayMicroseconds(2300);
		digitalWrite(pin, LOW);
		delayMicroseconds(2300);
	}
	digitalWrite(pin, LOW);
}
MyServoClass MyServo;