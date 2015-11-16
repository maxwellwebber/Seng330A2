#include "stdafx.h"
#include "MachineFactory.h"
#include <map>
#include <string>
using namespace std;

/// MachineFactory constructor.
/// This will create a new Machine Factory and
/// the prototype objects for each different machine.

MachineFactory::MachineFactory()
{
	machine_reference[TREADMILL] = new Treadmill("Generic Treadmill Brand");
	machine_reference[SQUAT_RACK] = new Squat_Rack("Generic Squat Rack Brand");
	machine_reference[BIKE] = new Bike("Generic Bike Brand");
}

/// MachineFactory Destructor.
/// This will remove the Machine Factory and
/// the prototype objects for each different machine
/// when they are no longer needed.

MachineFactory::~MachineFactory()
{
	delete machine_reference[TREADMILL];
	delete machine_reference[SQUAT_RACK];
	delete machine_reference[BIKE];
}

/// Machine creation function.
/// This will create a new machine by copying the prototype
/// and returning it as a new machine.

Machine* MachineFactory::createMachine(MACHINE_TYPE type)
{
	return machine_reference[type]->clone();
}
