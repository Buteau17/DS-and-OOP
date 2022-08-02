#include<iostream>
using namespace std;
//creating class , Calculate that would print
class Calculate
{
	//declaring public access modifier .
public:
	//Member function()
	//prints complex number: a+bi;
	void print(int a, int b) {
		if (a == 0 && b == 0) {
			cout << "0\n";
		}
		else if (a == 0) {
			if (b == 1)
				cout << "i\n";
			else if (b == -1)
				cout << "-i\n";
			else
				cout << b << "i\n";
		}
		else if (b == 0) {
			cout << a << endl;
		}
		
		else {
			if (b == 1)
				cout << a << "+i\n";
			else if (b == -1)
				cout << a << "-i\n";
			else
				cout << a << "+" << b << "i\n";
		}
	}
	//adding complex number(a1+b1i)
	void add(int a1, int b1, int a2, int b2) {
		//adding real parts
		int a = a1 + a2;
		//adding imaginary parts
		int b = b1 + b2;
		//print  the result
		print(a, b);
	}
	void multiply(int a1, int b1, int a2, int b2) {
		//calculating real part

		int a = a1 * a2 - b1 * b2;
		//calculating imaginary part
		int b = a1 * b2 + b1 * a2;
		//print the result
		
		print(a, b); 
	}

};
int main() {
	//creating object
	Calculate c;
	int n, a1, b1, a2, b2;
	cin >> n;
	char op;
	while (n--) {
		//taking operator : "+", "*", "or"
		cin >> op;
		switch (op) {
		case 'p':
		{
			cin >> a1 >> b1;
			c.print(a1, b1);
			break;
		}
		case '+':
		{
			cin >> a1 >> b1 >> a2 >> b2;
			c.add(a1, b1, a2, b2);
			break;

		}
		case '*':
		{
			cin >> a1 >> b1 >> a2 >> b2;
			c.multiply(a1, b1, a2 , b2);
			break;
		}
		}

	}
	return 0;
}
