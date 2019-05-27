#include "Strings.h"
//parametrized constructor
Strings::Strings(StepperClass &x, StepperClass &y) {//Stores address of stepper objects to control motors
	xad = &x;
	yad = &y;
}

//takes string as input
void Strings::getString() {//Take string input from Serial monitor
	s = "";
	Serial.println("Enter string");
	while (!Serial.available());//Wait unill enter is not pressed
	for (int n = 0; n < 200; n++) { //Sometimes while loop stops without taking all data
		while (Serial.available()) {
			s += (char)Serial.read();//Store it
		}
		delay(1);
	}
}

//prints space at the end of a word
void Strings::printspace()
{
	penUp();
	goto_point(xad->getSteps() + 94, yad->getSteps() + 0, *xad, *yad);//Move the motor some steps ahead
}

//prints a space at the end of every letter
void Strings::letterspace()
{
	penUp();
	goto_point(xad->getSteps() + 70, yad->getSteps() + 0, *xad, *yad);
}

//takes the pen to the origin of the string
void Strings::initString() {
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
}

//
void Strings::newline() {
	penUp();
	goto_point(0, yad->getSteps() + 50 + 94, *xad, *yad);
}

//the following functions print the capital letters A-Z
void Strings::printA() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 24, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 23, yad->getSteps() - 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 24, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
}

void Strings::printB() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 47, *xad, *yad);
}
void Strings::printC() {
	//pen up
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
}
void Strings::printD() {
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 37, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 37, yad->getSteps() + 0, *xad, *yad);
	penUp();
}
void Strings::printE() {
	//pen up
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 47, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
}
void Strings::printF() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() - 47, *xad, *yad);
}
void Strings::printG() {
	//pen up
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() - 94, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 9, *xad, *yad);
	goto_point(xad->getSteps() - 24, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 23, yad->getSteps() + 9, *xad, *yad);
}
void Strings::printH() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
}
void Strings::printI() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 24, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 24, yad->getSteps() + 0, *xad, *yad);
}
void Strings::printJ() {
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 24, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 24, *xad, *yad);
	goto_point(xad->getSteps() + 24, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 24, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
}
void Strings::printK() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	//pen up
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 47, *xad, *yad);
	//pen up
	penUp();
}
void Strings::printL() {
	//pen up
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	//pen up
	penUp();
}
void Strings::printM() {
	//pen down
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 24, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 23, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
	//pen up
	penUp();
}
void Strings::printN()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
}

void Strings::printO()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::printP()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	penUp();
}

void Strings::printQ()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::printR()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 35, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 35, yad->getSteps() + 35, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 12, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
}

void Strings::printS()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + -47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::printT()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 23, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 23, yad->getSteps() + 0, *xad, *yad);

}

void Strings::printU()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::printV()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 23, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 46, yad->getSteps() - 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 46, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
}
void Strings::printW()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 11, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 22, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 33, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 44, yad->getSteps() - 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 44, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
}

void Strings::printX()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
	penUp();
}

void Strings::printY()
{
	goto_point(xad->getSteps() + 23, yad->getSteps() + 0, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() - 23, yad->getSteps() - 47, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() + 46, yad->getSteps() + 0, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() - 23, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 23, yad->getSteps() + 0, *xad, *yad);

}

void Strings::printZ()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print1()
{
	goto_point(xad->getSteps() + 23, yad->getSteps() + 0, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() - 10, yad->getSteps() + 20, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() + 13, yad->getSteps() + 74, *xad, *yad);
}

void Strings::print2()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 70, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 24, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print3()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print4()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);

}

void Strings::print5()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print6()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print7()
{
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	penUp();
}

void Strings::print8()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}

void Strings::print9()
{

	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 47, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 47, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() - 0, yad->getSteps() + 47, *xad, *yad);
	penUp();
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
}

void Strings::print0()
{
	penDown();
	goto_point(xad->getSteps() + 0, yad->getSteps() - 94, *xad, *yad);
	goto_point(xad->getSteps() + 47, yad->getSteps() + 0, *xad, *yad);
	goto_point(xad->getSteps() + 0, yad->getSteps() + 94, *xad, *yad);
	goto_point(xad->getSteps() - 47, yad->getSteps() + 0, *xad, *yad);
	penUp();
}



void Strings::seperate_and_print(void)
{
	initString();
	Serial.println(s);
	s.toUpperCase();//Convert string to upper case
	int length_S = s.length();
	for (int i = 0; i < length_S; i = i + 1)
	{
		switch (s[i])
		{
		case 'A':
			printA();
			letterspace();
			break;

		case 'B':
			printB();
			letterspace();
			break;

		case 'C':
			printC();
			letterspace();
			break;

		case 'D':
			printD();
			letterspace();
			break;

		case 'E':
			printE();
			letterspace();
			break;

		case 'F':
			printF();
			letterspace();
			break;

		case 'G':
			printG();
			letterspace();
			break;

		case 'H':
			printH();
			letterspace();
			break;

		case 'I':
			printI();
			letterspace();
			break;

		case 'J':
			printJ();
			letterspace();
			break;
		case 'K':
			printK();
			letterspace();
			break;
		case 'L':
			printL();
			letterspace();
			break;
		case 'M':
			printM();
			letterspace();
			break;
		case 'N':
			printN();
			letterspace();
			break;
		case 'O':
			printO();
			letterspace();
			break;
		case 'P':
			printP();
			letterspace();
			break;
		case 'Q':
			printQ();
			letterspace();
			break;
		case 'R':
			printR();
			letterspace();
			break;
		case 'S':
			printS();
			letterspace();
			break;
		case 'T':
			printT();
			letterspace();
			break;
		case 'U':
			printU();
			letterspace();
			break;
		case 'V':
			printV();
			letterspace();
			break;
		case 'W':
			printW();
			letterspace();
			break;
		case 'X':
			printX();
			letterspace();
			break;
		case 'Y':
			printY();
			letterspace();
			break;
		case 'Z':
			printZ();
			letterspace();
			break;
		case '1':
			print1();
			letterspace();
			break;
		case '2':
			print2();
			letterspace();
			break;
		case '3':
			print3();
			letterspace();
			break;
		case '4':
			print4();
			letterspace();
			break;
		case '5':
			print5();
			letterspace();
			break;
		case '6':
			print6();
			letterspace();
			break;
		case '7':
			print7();
			letterspace();
			break;
		case '8':
			print8();
			letterspace();
			break;
		case '9':
			print9();
			letterspace();
			break;
		case '0':
			print0();
			letterspace();
			break;
		case '^':           //our own notation for a newline
			this->newline();
			break;
		case ' ':
			this->printspace();
			break;
		}
		if ((xad->getSteps() >= xad->get_limit() - 47) && (yad->getSteps() >= yad->get_limit())) {
			Serial.println("Grid is filled");
			break;//grid is filled
		}
		if (xad->getSteps() >= xad->get_limit() - 47) {//If line is filled, goto new line
			this->newline();
		}
	}
}
