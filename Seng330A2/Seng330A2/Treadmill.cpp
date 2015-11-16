#include "stdafx.h"
#include "Treadmill.h"
#include <iostream>
#include <string>
using namespace std;

/// Constructor for treadmill prototype.
/// every new treadmill created will be a copy of this.

Treadmill::Treadmill(string _name) {
	name = _name;
}

/// Constructor for treadmill copies.
/// every new treadmill created will use this constructor.
/// It will copy the attributes of the prototype treadmill.

Treadmill::Treadmill(const Treadmill& copy) {
	cout << "A Treadmill is being created with the name " << copy.name << endl;
	name = copy.name;
}

/// Treadmill clone function.
/// It will return a new copy of the prototype treadmill
/// using the treadmill copy constructor.

Machine* Treadmill::clone()
{
	return new Treadmill(*this);
}

/// Print name function.
/// It will print the name of the Treadmill.

void Treadmill::print()
{
	cout << "Treadmill, name: " << name << endl;
}

/// Change name function.
/// Changes the treadmill's name.

void Treadmill::changeName(string newName)
{
	cout << "The Treadmill's new name is: " << newName << endl;
	name = newName;
}

/// Destructor for treadmill prototype.
Treadmill::~Treadmill(){}
