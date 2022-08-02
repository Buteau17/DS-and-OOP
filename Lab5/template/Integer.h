#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Integer
{
private:
	vector<int> num;  //store the number
public:
	//constructor
	Integer(string number);	//default constructor

	//operation overload
	Integer operator +(const Integer& b);
	Integer operator -(const Integer& b);
	const vector <int> getnum() const{
		return num;
	}
	void setnum(int a, int i){
		num[i]=a;



	}

	bool bigger (const Integer b){
		vector<int> bnum= b.getnum();
		for ( int i=0 ; i<1000; i++){
			if(bnum[i]==num[i]){
				continue;
			}
			else if(num[i]>bnum[i]){
				return true;

			}
			else if(num[i]<bnum[i]){
				return false;
			}
		}
		return true;

	}


	//output overload
	friend ostream& operator << (ostream& out, const Integer& i);
};
#endif
