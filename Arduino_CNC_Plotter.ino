#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#define cs   10 //cs to pin10
#define dc   9  // dc to pin9
#define rst  12 //reset to pin12

#include "Strings.h"
#include "myServo.h"
#include "Bitmap.h"
#include "Stepper.h"

void string(void);
void bitmap(void);
void star(void);

int command_type = 0;//global variable

TFT TFTscreen = TFT(cs, dc, rst);//global tft object
void setup()
{
	pinMode(7, OUTPUT); //output of 5V
	digitalWrite(7, HIGH);//use it as 5V
	Serial.begin(115200);//start serial communication

	TFTscreen.begin();//tft functions starts
	TFTscreen.background(0, 0, 0);// clear the screen with a black background
	TFTscreen.stroke(0, 255, 0);// set the font color to white
	TFTscreen.setTextSize(2.7);// set the font size
	TFTscreen.fill(0, 255, 0);
	TFTscreen.text("Welcome to\nthe CNC\ndesign\ndisplay\ninterface!\n ", 0, 0);// write the text to the top left corner of the screen
	delay(500);

	MyServoClass s;//To take pen in initial position//Only Constructor will do the work
}

void loop()
{
	if (Serial) {//excutes only when serial port is open
		if (command_type == 0) {
		command_input:  Serial.println("Enter 1 for string, 2 for bitmap and 3 for a star.");
			TFTscreen.background(0, 0, 0);// clear the screen with a black background
			TFTscreen.text(" Enter 1 for string, 2 for bitmap and 3 for a hardcoded Bitmap.", 0, 0);
			while (!Serial.available());//Wait for serial input

			command_type = Serial.parseInt();			//take integer input

			for (int temp = 0; temp != 10;)//refresh serial buffer
				temp = Serial.read();

			if (command_type < 1 || command_type > 3) {//If input is not within range
				Serial.print(command_type);
				Serial.println(" ?! This is an Invalid command. Enter again\n");
				TFTscreen.background(0, 0, 0);
				TFTscreen.text(" ?! This is an Invalid command. Enter again\n ", 0, 0);

				command_type = 0;
				goto command_input;
			}
		}
		switch (command_type) {
		case 1:
			string();
			break;
		case 2:
			bitmap();
			break;
		case 3:
			star();
			break;
		}
		Serial.println("Do you want to run again ?\nEnter 1 for yes and and any other for no !");
		while (!Serial.available());//Wait for serial input
		command_type = Serial.parseInt();			//take integer input

		if (command_type != 1)
		while (true);//Stop the code from running again and again
		else
			command_type == 0;//Restart code and take input when compiler goes to start of loop
	}//end if(serial)
}//end loop

void string(void){
	StepperClass x(2, 3, 4, 5, 600);//make x object
	StepperClass y(A3, A2, A1, A0, 800);//make y object
	TFTscreen.setTextSize(2.3);
	TFTscreen.stroke(0, 255, 0);
	TFTscreen.text("Enter string\nin Serial\n Monitor", 0, 0);
	Strings myString(x, y);//start string functions
	myString.getString();//input string
	TFTscreen.background(0, 0, 0);
	TFTscreen.fill(0, 255, 0);
	Serial.println("String printing starts now");
	TFTscreen.text("String\nPrinting\nStarts now\n", 0, 0);
	delay(1000);
	myString.seperate_and_print();//this function print the string
	Serial.println("Printing complete\nThank you:)");

	TFTscreen.text(" Printing complete\nThank you:) ", 0, 0);
	goto_point(0, 0, x, y);//take head to initial position
}

void bitmap(void){
	StepperClass x(2, 3, 4, 5, 600);//make x object
	StepperClass y(A3, A2, A1, A0, 800);//make y object
	TFTscreen.setTextSize(2.3);
	TFTscreen.stroke(0, 255, 0);
	TFTscreen.text("Enter string\nin Serial\n Monitor", 0, 0);
	Bitmap mybitmap;
	mybitmap.map_input();
	TFTscreen.background(0, 0, 0);
	TFTscreen.text("Printing\nis started\nEnjoy", 0, 0);
	mybitmap.plotBitmap(x, y);
	TFTscreen.background(0, 0, 0);
	TFTscreen.text(" Bitmap \n plotted \nThank you:) ", 0, 0);
	goto_point(0, 0, x, y);//take head to initial position
}

void star(void){
	StepperClass x(2, 3, 4, 5, 600);//make x object//600 is maximum step limit in x direction
	StepperClass y(A3, A2, A1, A0, 800);//make y object
	TFTscreen.setTextSize(2.3);
	TFTscreen.stroke(0, 255, 0);
	TFTscreen.text("Star printing\nStarted", 0, 0);
	Serial.println("Printing started");
	printStar(x, y);//this function prints star
	Serial.println("Printing Ended\nThank You:)");
	TFTscreen.background(0, 0, 0);//clear background
	TFTscreen.text(" Printing complete\nThank you:) ", 0, 0);
	goto_point(0, 0, x, y);
}