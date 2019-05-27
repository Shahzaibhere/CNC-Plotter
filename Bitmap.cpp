// 
// 
//
#include "Bitmap.h"


void serial_flush(void){//cler all input buffer
	for (int temp = 0; temp != 10;)
		temp = Serial.read();
}


Bitmap::Bitmap(void) :rows(0), coloumns(0)
{
}

void Bitmap::map_input(void){
	Serial.println("Enter width\n");//take number of rows and coloumns
	while (!Serial.available());
	coloumns = Serial.parseInt();

	serial_flush();//Remove the leftover buffer i.e. newline character
	Serial.println("Enter height\n");
	while (!Serial.available());
	rows = Serial.parseInt();

	bool_ptr = new bool*[rows];//make a dynamic boolean array for numbers(0/1)
	for (int i = 0; i < rows; i++){
		bool_ptr[i] = new bool[coloumns];
	}

	for (int i = 0; i < rows; i++){//Initialize every element to 0 to avoid errors
		for (int j = 0; j < coloumns; j++){
			bool_ptr[i][j] = 0;
		}
	}

	serial_flush();
	Serial.println("Enter array in form of text/string");
	while (!Serial.available());
	char in_chr;
	for (int n = 0, i = 0, j = 0; n < 50; n++){//Sometimes while loop stops without taking all data. so "for" is to repeat it sometimes
		while (Serial.available()>0){
			in_chr = (char)Serial.read();//take input
			if (in_chr == '0'){//if it is 0, store 0 in boolean array and increment indexes
				bool_ptr[i][j++] = 0;

				if (j == coloumns){//If a row is complete, goto next row
					j = 0;
					i++;
				}
				if (i == rows){//if space is finished
					n = 200;//to break for loop
					break;//to break while loop
				}
			}
			else if (in_chr == '1'){//if it is 1, store 1 in boolean array and increment indexes
				bool_ptr[i][j++] = 1;
				if (j == coloumns){//If a row is complete, goto next row
					j = 0;
					i++;
				}
				if (i == rows){//if space is finished
					n = 200;//to break for loop
					break;//to break while loop
				}
			}
		}
		delay(1);
	}
	Serial.println("Thank you");
}
void Bitmap::plotBitmap(StepperClass& x, StepperClass& y){//plot bitmap from array input taken before
	 Serial.println("Printing started");
	for (int i = 0; i < rows; i++, y++)//Increment control variable and current row
	{
		if ((i % 2) == 0)
		{
			for (int j = 0; j < coloumns; j++, x++)
			{
				if (bool_ptr[i][j])//if we need to mark, mark. Otherwise not
				{
					MyServoClass::penDown();
					delay(100);
					MyServoClass::penUp();
				}
			}
		}
		else if ((i % 2) != 0)
		{
			for (int j = coloumns - 1; j >= 0; j--, x--)//This arrangement is so that head doesn't need to go to starting of row everytime
			{
				if (bool_ptr[i][j])
				{
					MyServoClass::penDown();
					delay(80);
					MyServoClass::penUp();
				}
			}
		}
	}
	Serial.println("Printing ended. Thank you");
}

Bitmap::~Bitmap(){
	for (int i = 0; i < rows; ++i)//Empty the dynamically allocated memory
	{
		delete[] bool_ptr[i];
	}
	delete[] bool_ptr;

}