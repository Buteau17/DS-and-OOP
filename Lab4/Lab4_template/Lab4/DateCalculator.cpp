#include "DateCalculator.h"

using namespace std;

DateCalculator::DateCalculator():year(2000),month(1),day(1), changeDays(0){}


void DateCalculator::readFile(const char *fileName) {
	//TODO:
	//Read the data from the txt file.
	//The file is in the Lab4_template/Lab4.
	// 
	//Hint: You can use get() to get a character in ifstream.
	//      You can use getline() to get one line in the txt file.
	//      You can use atoi() or stoi() to change variable type from string to int
}

void DateCalculator::add() {
	//TODO:
	//Calculate the date add the changeDays.
}

void DateCalculator::minus() {
	//TODO:
	//Calculate the date minus the changeDays.
}

bool DateCalculator::isLeapYear(int year_) {
	//TODO: 
	//Determine whether year_ is a leap year.
}

void DateCalculator::showDay() {
	//TODO: 
	//The function output the date on the screen.
	//Hint: You can use setw() to set the length of the number.
	//      You can use setfill('c') to fill 'c' to the empty space.
	//      Two functions of above is in iomanip header file. 
}