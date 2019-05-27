// Stepper.h

#ifndef _STEPPER_h
#define _STEPPER_h
#include "myServo.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#define LEASTSPEED 5500//Define least speed.This will be used by delayMicroseconds() and by goto_point() function
class StepperClass
{
	int motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4;
	int limit, speeds = LEASTSPEED;//Maximum imit in which stepper could move freely and speed for delay
	int steps;//current steps
public:
	StepperClass(int pin1, int pin2, int pin3, int pin4, int l);//Constructer
	void increaseSteps(unsigned int s);
	void increaseSteps_withoutDelay(unsigned int s);//Normally increase/decrease functions wait till motor turns. But this function does not
	void operator ++(int);//Short form of increaseSteps(1). It requires less processing time due to less calculation
	void decreaseSteps(int s);
	void decreaseSteps_withoutDelay(int s);
	void operator --(int);
	void all_outputsLow(void);//It is to avoid power loss
	int get_limit(void);
	int getSteps();
	void setSpeeds(int s);
	void gotostep(int s);
	friend void goto_point(int x, int y, StepperClass&, StepperClass&);//Go fromm current position to designated position in a straight line
	friend void printStar(StepperClass&, StepperClass&);
};

extern StepperClass Stepper;

#endif