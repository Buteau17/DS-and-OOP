/*
*	Spring 2022
*	OOP Midterm Two
*	Question
*/
#include <iostream>
#include <vector>
#include <time.h>			// time
using namespace std;

namespace {
	double getRandomNumber(double minValue, double maxValue) {
		return minValue 
			+ (maxValue- minValue) * rand() / (double) RAND_MAX;
	}
};
class MonteCarlo {
protected:
	vector<double> xArr;
	vector<double> yArr;
	int numSamples;			// total number of samples to be generated 
	double area;			// use this variable to store the area in each case
public:
	MonteCarlo() {
		numSamples = 0;
		area = 0;
	}

	void go() {
		bool flg = true;
		while (flg) {
			int option;
			showOptions();
			cout << "Please enter an option:";
			cin >> option;
			flg = handleOption( option );

		}
	}
protected:
	void quit();
	bool handleOption(int option);
	void showOptions() const;
	//
	void showArea() const;
	//
	void inputNumberOfSamples(const char* msg);
	void handle_CaseOne();
	void handle_CaseTwo();
	void handle_CaseThree();
	//
	void generateSamplesFor_CaseOne();
	void computeAreaFor_CaseOne();
	//
	void generateSamplesFor_CaseTwo();
	void computeAreaFor_CaseTwo();
	//

	void generateSamplesFor_CaseThree();
	void computeAreaFor_CaseThree();
	//
};

void MonteCarlo::showArea() const
{
	cout << "Area:" << area << endl;
}

void MonteCarlo::showOptions() const
{
	cout << "Key usage====================" << endl;
	cout << "0: Quit the program" << endl;
	cout << "1: Case One" << endl;
	cout << "2: Case Two" << endl;
	cout << "3: Case Three" << endl;
}


// This function inputNumberOfSamples( const char * ) is correct.
// It asks the user to inpute the number of samples that will be generated.
void MonteCarlo::inputNumberOfSamples(const char *msg)
{
	cout << "Case:" << msg << endl;
	cout << "Please input the number of samples:";
	cin >> numSamples;
}

// This function handleOption( int ) is correct.
bool MonteCarlo::handleOption(int option)
{
	bool flg = true;
	switch (option) {
	case 0:
		quit();
		flg = false;
		break;
	case 1:
		handle_CaseOne();
		break;
	case 2:
		handle_CaseTwo();
	break;
	case 3:
		handle_CaseThree();
		break;
	}
	return flg;
}

void MonteCarlo::quit()
{
	/*
	* Please modify or add your own stuff
	*/
	cout << "The program will be terminated soon...." << endl;
	cout << "Student Name: BUTEAU Ralph Kedy Willens" << endl;
	cout << "Student ID: 109550198" << endl;
}
//
void MonteCarlo::generateSamplesFor_CaseOne() {
	/*
	* Please modify or add your own stuff
	*/
	double xmin = 0;
	double xmax = 1;
	double ymin = 0;
	double ymax = 1;
	xArr.clear();
	yArr.clear();
	for (int i = 0; i < numSamples; ++i) {
		double x = 0.0;
		double y = 0.0;

		x = getRandomNumber(xmin, xmax);
		y = getRandomNumber(ymin, ymax);
		//y = 0.0;							// This line is wrong
		xArr.push_back(x);
		yArr.push_back(y);
	}
}

void MonteCarlo::computeAreaFor_CaseOne() {
	int numInteriorPoints = 0;
	int total_sample_num = xArr.size();
	cout << total_sample_num << endl;
	for (int i = 0; i < xArr.size(); ++i) {
		double x = xArr[i];
		double y = yArr[i];
		double dis = (x+0) * (x+0) + (y+0) * (y+0);
		if (dis <= 1)
			numInteriorPoints++;
	}
	area = ((double)numInteriorPoints / (double)xArr.size());
	if (total_sample_num == 0) area = 0;
	//double area = ratio * (xmax - xmin) * (ymax - ymin);
}

//
void MonteCarlo::generateSamplesFor_CaseTwo() {
	/*
	* Please modify or add your own stuff
	*/
	double xmin = 0;
	double xmax = 1;
	double ymin = 0;
	double ymax = 1;
	xArr.clear();
	yArr.clear();
	for (int i = 0; i < numSamples; ++i) {
		double x = 0.0;
		double y = 0.0;

		x = getRandomNumber(xmin, xmax);
		y = getRandomNumber(ymin, ymax);
		//y = 0.0;							// This line is wrong
		xArr.push_back(x);
		yArr.push_back(y);
	}
}

void MonteCarlo::computeAreaFor_CaseTwo() {
	int numInteriorPoints = 0;
	int total_sample_num = xArr.size();
	for (int i = 0; i < xArr.size(); ++i) {
		double x = xArr[i];
		double y = yArr[i];
		double dis = (x+0) * (x+0) + (y+0) * (y+0);
		if (0.25 <= dis && dis <= 1)
			numInteriorPoints++;
	}
	area = (numInteriorPoints / (double)xArr.size());
	if (total_sample_num == 0) area = 0;
}

//

void MonteCarlo::generateSamplesFor_CaseThree() {
	/*
	* Please modify or add your own stuff
	*/
	double xmin = 0;
	double xmax = 1;
	double ymin = 0;
	double ymax = 1;
	xArr.clear();
	yArr.clear();
	for (int i = 0; i < numSamples; ++i) {
		double x = 0.0;
		double y = 0.0;

		x = getRandomNumber(xmin, xmax);
		y = getRandomNumber(ymin, ymax);
		//y = 0.0;							// This line is wrong
		xArr.push_back(x);
		yArr.push_back(y);
	}
}

void MonteCarlo::computeAreaFor_CaseThree() {
	int numInteriorPoints = 0;
	int total_sample_num = xArr.size();

	for (int i = 0; i < xArr.size(); ++i) {
		double x = xArr[i];
		double y = yArr[i];
		double dis = (x + 0) * (x + 0) + (y+0) * (y+0);
		double dis2 =(x+0) * (x + 0) + (y-0.5) * (y-0.5);
		double dis3 = (x-0.5) * (x-0.5) + (y + 0) * (y + 0);

		if ((dis <= 1 && dis2 > 0.25 && dis3 > 0.25) || (dis2 <= 0.25 && dis3 <= 0.25))
			numInteriorPoints++;
	}
	area = (numInteriorPoints / (double)xArr.size());
	if (total_sample_num == 0) area = 0;
}

//
void MonteCarlo::handle_CaseOne()
{
	inputNumberOfSamples("One");
	generateSamplesFor_CaseOne();
	computeAreaFor_CaseOne();
	showArea();
}

void MonteCarlo::handle_CaseTwo()
{
	inputNumberOfSamples("Two");
	generateSamplesFor_CaseTwo();
	computeAreaFor_CaseTwo();
	showArea();
}

void MonteCarlo::handle_CaseThree()
{
	inputNumberOfSamples("Three");
	generateSamplesFor_CaseThree();
	computeAreaFor_CaseThree();
	showArea();
}
int main(int argc, char* argv[])
{
	MonteCarlo m;
	m.go();
	system("pause");
	return 0;
}


