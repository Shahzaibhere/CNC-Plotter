// myServo.h
#ifndef _MYSERVO_h
#define _MYSERVO_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
class MyServoClass
{
protected:
	int pin;
public:
	MyServoClass(void);//Initialize the pin number
	void penUp(void);
	void penDown(void);
	void endServo(void);//This function can be used to put pen in high position i.e.neither down or up position
};

extern MyServoClass MyServo;

#endif
