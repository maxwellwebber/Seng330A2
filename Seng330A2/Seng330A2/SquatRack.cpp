#include "stdafx.h"
#include "SquatRack.h"
#include <iostream>
#include <string>
using namespace std;

/// Constructor for Squat Rack prototype.
/// every new Squat Rack created will be a copy of this.

Squat_Rack::Squat_Rack(string _name) {
	name = _name;
	type = "Squat Rack";
}

/// Constructor for Squat Rack copies.
/// every new Squat Rack created will use this constructor.
/// It will copy the attributes of the prototype Squat Rack.

Squat_Rack::Squat_Rack(const Squat_Rack& copy) {
	name = copy.name;
	type = copy.type;
}

/// Squat Rack clone function.
/// It will return a new copy of the prototype Squat Rack
/// using the Squat Rack copy constructor.

Machine* Squat_Rack::clone()
{
	return new Squat_Rack(*this);
}

/// Print name function.
/// It will print the name of the Squat Rack.

string Squat_Rack::print()
{
	return "Squat Rack, name: " + name;
}

/// Change name function.
/// Changes the Squat rack's name.

void Squat_Rack::changeName(string newName, bool printit)
{
	if (printit)
		cout << "The Squat Rack's new name is: " << newName << endl;
	name = newName;
}

/// Destructor for Squat Rack.
Squat_Rack::~Squat_Rack()
{
}
