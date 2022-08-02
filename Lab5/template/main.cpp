#include <iostream>
#include <fstream>
#include "Integer.h"

using namespace std;

//read the data from the file
void readFile(const char* fileName);


int main()
{
	readFile("input1.txt");
	return 0;
}

void readFile(const char* fileName) {
	ifstream inputFile;

	//TODO: Read the input file here.
	//int lines = ...
	ifstream inFile;
	inFile.open("input1.txt");
	int lines;
	inFile>>lines; //inFile.ignore();
	string tmp;
	getline(inFile , tmp);
	cout << lines << '\n';


	for (size_t i = 0; i < lines; i++)
	{
		Integer a(""), b(""), answer("");

		//TODO: Implement your add or minus

		//answer = a + b;
		//answer = a - b;
	string n="";
	string temp="";
	getline(inFile , n);
	// cout << n << '\n';
	bool plus=0;
	bool minus=0;
	bool negative=0;
	// cout << n.size() << '\n';
	for(int j =0; j<n.size()-1;  j++){
		if (n[j]=='+'){
			plus=true;
			// cout << temp << '\n';
			a=Integer(temp);
			temp="";
		}
		else if (j > 0 && n[j]=='-'){
			minus=true;

			// cout << temp << '\n';
			a=Integer(temp);
			temp="";

		}
		else if(j == 0 && n[j] == '-') {

		}
		else{
			temp+=n[j];
		}
	}
	// cout << temp << '\n';
	// cout << n[n.size()-1] << '\n';
	if(i == lines-1) temp += n[n.size()-1];

	b=Integer(temp);
	temp = "";

	// const vector <int> vec = b.getnum();
	// cout << vec[997] << vec[998] << vec[999] << '\n';

	if (plus ==true){
		if (n[0]== '-'){
			if (b.bigger(a)){
				answer=b-a;
			}
			else {
				answer=a-b;
				negative=1;
			}


		}
		else {
			answer =a+b;

		}
	}
	else{
		if (n[0]== '-'){
			answer=a+b;
			negative=1;
		}
		else{
				if (b.bigger(a)){
					answer=b-a;
					negative=1;
				}
				else{
					answer=a-b;
				}
		}
	}


		cout << i + 1 << endl;
		cout << "num1: " << a << endl;
		cout << "num2: " << b << endl;

		cout << "result: " ;
		if(negative==1)cout<<'-';
	cout	<< answer <<endl << endl;

	}

	inputFile.close();
}
