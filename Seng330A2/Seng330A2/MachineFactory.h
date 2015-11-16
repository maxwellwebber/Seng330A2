#pragma once
#include "Machine.h"
#include "Bike.h"
#include "Treadmill.h"
#include "SquatRack.h"

using namespace std;
/// An Enum to specify what type of machine the object is.
/// Thisis an Enum to specify what type of machine the object is. 
/// You can make it a TREADMILL, SQUAT_RACK or BIKE.

enum MACHINE_TYPE
{
	TREADMILL,
	SQUAT_RACK,
	BIKE
};

/// Machine Factory class.
/// This creates the prototype objects and
/// has a method for cloning new objects from the prototype.

class MachineFactory
{
private:
	map<MACHINE_TYPE, Machine* > machine_reference;

public:
	MachineFactory();
	~MachineFactory();
	Machine* createMachine(MACHINE_TYPE type);

};

