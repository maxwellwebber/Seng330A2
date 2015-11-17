#include "stdafx.h"
#include "Bike.h"
#include <iostream>
#include <string>
using namespace std;

/// Constructor for Bike prototype.
/// every new Bike created will be a copy of this.

Bike::Bike(string _name) {
	name = _name;
	type = "Bike";
}

/// Constructor for Bike copies.
/// every new Bike created will use this constructor.
/// It will copy the attributes of the prototype Bike.

Bike::Bike(const Bike& copy) {
	name = copy.name;
	type = copy.type;
}

/// Bike clone function.
/// It will return a new copy of the prototype Bike
/// using the Bike copy constructor.

Machine* Bike::clone()
{
	return new Bike(*this);
}

/// Print name function.
/// It will print the name of the Bike.

string Bike::print()
{
	return "Bike, name: " + name;
}

/// Change name function.
/// Changes the Bike's name.

void Bike::changeName(string newName, bool printit)
{
	if (printit)
		cout << "The Bike's new name is: " << newName << endl;
	name = newName;
}

/// Destructor for Bike.
Bike::~Bike()
{
}
