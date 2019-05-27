//
//
//


#include "Stepper.h"
StepperClass::StepperClass(int pin1, int pin2, int pin3, int pin4, int l) : motor_pin_1(pin1), motor_pin_2(pin2), motor_pin_3(pin3), motor_pin_4(pin4), limit(l), steps(0)//Take program starting postion as initial position as we cannot sense current position
{								//Constructor: Declares pins for OUTPUT
	pinMode(motor_pin_1, OUTPUT);
	pinMode(motor_pin_2, OUTPUT);
	pinMode(motor_pin_3, OUTPUT);
	pinMode(motor_pin_4, OUTPUT);
}
void StepperClass::increaseSteps(unsigned int s)
{//Increase given number of steps 
	while (s > 0) {//Steps count
		switch (steps % 4) {//Which pin order is to be applied
		case 0:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 1:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 2:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		case 3:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		}
		delayMicroseconds(speeds);//Wait for motor to turn to its position
		all_outputsLow();//Turn all outputs off so that current may not used up needlessly
		s--;
		steps++;//Increment steps variable
	}
}
void StepperClass::operator ++(int) {
	switch (steps % 4) {//It is short form of increase steps function.
	case 0:					//It is to save processing power
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
	case 1:
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
	case 2:
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
	case 3:
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
	}
	delayMicroseconds(speeds);//Wait for stepper to turn
	all_outputsLow();
	steps++;
}

void StepperClass::increaseSteps_withoutDelay(unsigned int s)
{
	while (s > 0) {
		switch (steps % 4) {
		case 0:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 1:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 2:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		case 3:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		}
		s--;
		steps++;
	}
}
void StepperClass::decreaseSteps(int s) {
	while (s > 0) {
		switch (steps % 4) {
		case 3:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 2:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 1:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		case 0:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		}
		delayMicroseconds(speeds);
		all_outputsLow();
		s--;
		steps--;
	}
}
void StepperClass::operator --(int) {
	switch (steps % 4) {//Short form of decrease steps function
	case 3:
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
	case 2:
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
	case 1:
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
	case 0:
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
	}
	delayMicroseconds(speeds);
	all_outputsLow();
	steps--;
} 
void StepperClass::decreaseSteps_withoutDelay(int s) {//This function is used in the goto_point function
	while (s > 0) {
		switch (steps % 4) {
		case 3:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 2:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
			break;
		case 1:
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		case 0:
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
			break;
		}
		s--;
		steps--;
	}
}
void StepperClass::all_outputsLow(void) {//Pull all outputs to low
	digitalWrite(motor_pin_1, LOW);
	digitalWrite(motor_pin_2, LOW);
	digitalWrite(motor_pin_3, LOW);
	digitalWrite(motor_pin_4, LOW);
}
int StepperClass::get_limit(void)//Get the maximum limit of stepper object
{
	return limit;
}
int StepperClass::getSteps()//Return the current steps
{
	return steps;
}
void StepperClass::setSpeeds(int s)//Set the speed if we want
{
	speeds = s;
}

void StepperClass::gotostep(int s)//This function is not used but it can be used when we will expand project
{
	if (steps > s)
		decreaseSteps(steps - s);
	else if (steps < s)
		increaseSteps(s - steps);
	else
		return;
}

void goto_point(int x_p, int y_p, StepperClass& x, StepperClass& y) {//It is most complex function of our code. It moves head from current position to parameterized point, diagonally
	bool x_reached = false;//A check weather specific position is reached or not
	bool y_reached = false;
	int num_x = x_p - x.steps;//How much steps to move
	int num_y = y_p - y.steps;

	float primeryX = (float)abs(num_y) * 1000.0 / (float)pow((float)num_x * num_x + (float)num_y * num_y, 0.5); //How much delay should be given so that it
	float primeryY = (float)abs(num_x) * 1000.0 / (float)pow((float)num_x * num_x + (float)num_y * num_y, 0.5); //travels hypotenusely between 2 points

	if (0 == primeryX || 0 == primeryY) {//If any value is 0, make it 1 to avoid errors
		primeryX += 1.0;
		primeryY += 1.0;
	}
	float primery2X = primeryX, primery2Y = primeryY;
	for (float n = 2; primery2X < LEASTSPEED || primery2Y < LEASTSPEED; n += 1.0) {//Make sure no delay is lesser than least value
		primery2X = primeryX * n;//Increment by fixed ratios
		primery2Y = primeryY * n;
	}



	unsigned int x_delay = primery2X;//Convert from float to unsigned int because delayMicrosecond() take input of this type
	unsigned int y_delay = primery2Y;

	if (num_x >= 0 && num_y >= 0) {//If x steps and y steps, both have to increase:
		unsigned long XpreviousMicros = micros();
		unsigned long YpreviousMicros = micros();

		while (!x_reached || !y_reached) {  //while both positions are not reached, continue to move
			if (x.steps == x_p) x_reached = true;//A check if x position is reached
			if (micros() - XpreviousMicros >= x_delay && x_reached == false) {//It is a method of delay without stopping of whole program
				x.increaseSteps_withoutDelay(1);
				XpreviousMicros = micros();//Increment XpreviousMicros
			}
			if (y.steps == y_p) y_reached = true;//A check if y position is reached
			if (micros() - YpreviousMicros >= y_delay && y_reached == false) {
				y.increaseSteps_withoutDelay(1);
				YpreviousMicros = micros();
			}
		}
	}
	else if (num_x >= 0 && num_y <= 0) {//If x steps have to increase and y steps have to decrease
		unsigned long XpreviousMicros = micros();
		unsigned long YpreviousMicros = micros();

		while (!x_reached || !y_reached) {  //while both positions are not reached, continue to move
			if (x.steps == x_p) x_reached = true;
			if (micros() - XpreviousMicros >= x_delay && x_reached == false) {
				x.increaseSteps_withoutDelay(1);
				XpreviousMicros = micros();
			}
			if (y.steps == y_p) y_reached = true;
			if (micros() - YpreviousMicros >= y_delay && y_reached == false) {
				y.decreaseSteps_withoutDelay(1);
				YpreviousMicros = micros();
			}
		}
	}

	else if (num_x <= 0 && num_y >= 0) {//If y steps have to increase and x steps have to decrease
		unsigned long XpreviousMicros = micros();
		unsigned long YpreviousMicros = micros();

		while (!x_reached || !y_reached) {  //while both positions are not reached, continue to move
			if (x.steps == x_p) x_reached = true;
			if (micros() - XpreviousMicros >= x_delay && x_reached == false) {
				x.decreaseSteps_withoutDelay(1);
				XpreviousMicros = micros();
			}
			if (y.steps == y_p) y_reached = true;
			if (micros() - YpreviousMicros >= y_delay && y_reached == false) {
				y.increaseSteps_withoutDelay(1);
				YpreviousMicros = micros();
			}
		}
	}

	else if (num_x <= 0 && num_y <= 0) {//If x steps and y steps, both have to decrease:
		unsigned long XpreviousMicros = micros();
		unsigned long YpreviousMicros = micros();

		while (!x_reached || !y_reached) {  //while both positions are not reached, continue to move
			if (x.steps == x_p) x_reached = true;
			if (micros() - XpreviousMicros >= x_delay && x_reached == false) {
				x.decreaseSteps_withoutDelay(1);
				XpreviousMicros = micros();
			}
			if (y.steps == y_p) y_reached = true;
			if (micros() - YpreviousMicros >= y_delay && y_reached == false) {
				y.decreaseSteps_withoutDelay(1);
				YpreviousMicros = micros();
			}
		}
	}
	x.all_outputsLow();//Make all outputs low to avoid power loss
	y.all_outputsLow();
	Serial.print("Current x coordinate: ");//Also print the current position
	Serial.println(x_p);
	Serial.print("Current y coordinate: ");
	Serial.println(y_p);
	Serial.println("");
}
void printStar(StepperClass& x, StepperClass& y){//A hardcoded star
	MyServoClass s;
	goto_point(45, 250, x, y);
	s.penDown();
	goto_point(185, 245, x, y);
	goto_point(230, 115, x, y);//Defined points
	goto_point(275, 245, x, y);//With the help of goto_point function, we can draw many countless shapes
	goto_point(410, 250, x, y);
	goto_point(300, 325, x, y);
	goto_point(340, 460, x, y);
	goto_point(230, 385, x, y);
	goto_point(115, 460, x, y);
	goto_point(155, 330, x, y);
	goto_point(45, 250, x, y);
	s.penUp();
	goto_point(0, 0, x, y);
}