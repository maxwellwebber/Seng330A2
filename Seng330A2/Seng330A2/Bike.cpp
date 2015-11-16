#include "stdafx.h"
#include "Bike.h"
#include <iostream>
#include <string>
using namespace std;

/// Constructor for Bike prototype.
/// every new Bike created will be a copy of this.

Bike::Bike(string _name) {
	name = _name;
}

/// Constructor for Bike copies.
/// every new Bike created will use this constructor.
/// It will copy the attributes of the prototype Bike.

Bike::Bike(const Bike& copy) {
	cout << "A Bike is being created with the name " << copy.name << endl;
	name = copy.name;
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

void Bike::print()
{
	cout << "Bike, name: " << name << endl;
}

/// Change name function.
/// Changes the Bike's name.

void Bike::changeName(string newName)
{
	cout << "The Bike's new name is: " << newName << endl;
	name = newName;
}

/// Destructor for Bike.
Bike::~Bike()
{
}
