#pragma once
#ifndef STAFF_H
#include "role.h"
#include "magician.h"
#include <string>
using namespace std;

class Staff {
public:
	Staff(string staffName) :name(staffName), damage(10) {

	}
	void equipable(Role* role) {
		// TODO : refer to spec
		if(isMagician(role))
		cout << role->getID() << " can equip staff_" <<this-> name<< endl;
	}

private:
	string name;
	int damage;
	bool isMagician(Role* role) {
		// TODO : refer to spec
		 Magician* mag = dynamic_cast<Magician*>(role);
		if (mag == NULL) {
		
			cout << "error bad_cast." << endl; return false;
		 }
		 else {
			//cout <<role->getID()<< " is  a magician" << endl;  
			return true;
		 }
	}
};
#endif
