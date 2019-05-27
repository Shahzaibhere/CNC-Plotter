// Bitmap.h

#include "Stepper.h"

#include "myServo.h"
#ifndef _BITMAP_h
#define _BITMAP_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
class Bitmap :private MyServoClass{
	int rows, coloumns;
	bool** bool_ptr;//Double pointer variable to point to bool array
public:
	Bitmap(void);
	void map_input(void);//ask for bitmap array to input
	void plotBitmap(StepperClass&, StepperClass&);//plot bitmap from array input before

	/*We made another option to print a bitmap of hardcoded array (3 arrays were hardcoded and their printing functions were made). But it 
	continuously gave unhandled exception error/memory error/runtime error,which made arduino auto-restart everytime it ran.
	(It took us 12 hours to find the cause) So in order to stablize the code, we removed that part entirely*/

	~Bitmap();//Will destroy the dynamically allocated apace for array
};

#endif
