
#include "Stepper.h"
#include "myServo.h"
#ifndef _STRINGS_h
#define _STRINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
class Strings : private MyServoClass {

protected:
	StepperClass* xad;//Variables to store addresses of stepper objects
	StepperClass* yad;
	String s;
public:
	Strings(StepperClass &, StepperClass &);  //constructor that takes the adress of the two motors
	void initString(void);            //takes the pen to the origin of letter(bottom left)
	void printspace(void);            //prints a space (after a word)
	void letterspace(void);           //prints a space between every letter
	void newline(void);             //goes to a new line when x-limit is reached
	void seperate_and_print(void);        //separates string into characters and call the respective print function
	void getString(void);           //takes input string

	//following functions print the capital letters A-Z

	void printA(void);
	void printB(void);
	void printC(void);
	void printD(void);
	void printE(void);
	void printF(void);
	void printG(void);
	void printH(void);
	void printI(void);
	void printJ(void);
	void printK(void);
	void printL(void);
	void printM(void);
	void printN(void);
	void printO(void);
	void printP(void);
	void printQ(void);
	void printR(void);
	void printS(void);
	void printT(void);
	void printU(void);
	void printV(void);
	void printW(void);
	void printX(void);
	void printY(void);
	void printZ(void);
	void print1(void);
	void print2(void);
	void print3(void);
	void print4(void);
	void print5(void);
	void print6(void);
	void print7(void);
	void print8(void);
	void print9(void);
	void print0(void);
};

#endif