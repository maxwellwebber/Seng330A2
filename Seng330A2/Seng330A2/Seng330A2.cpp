#include "stdafx.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <istream>
#include <fstream>


#include "Machine.h"
#include "MachineFactory.h"



using namespace std;

const int MAX_GYM_SIZE = 64;
const string INVALID_SELECTION = "INVALID_STRING";

// function for saving the classes to a file named savestate.txt
void save(Machine** machineArray, int front) {
	ofstream saveF;
	saveF.open("savestate.txt");

	for (int i = 0; i < front; i++) {
		if (i < front - 1)
			saveF << machineArray[i]->print() << endl;
		else 
			saveF << machineArray[i]->print();
	}
	cout << "done saving.\n";
	saveF.close();
}

// function for loading the classes from a file named savestate.txt
int load(Machine** machineArray, MachineFactory* theMachineFactory) {

	ifstream loadF;
	int front = 0;
	loadF.open("savestate.txt");
	if (loadF.fail()) return 0;
	string name, type;

	while (!loadF.eof()) {	

		getline(loadF, type,',');
		loadF.ignore(256, ':');
		loadF.ignore(256, ' ');
		getline(loadF, name);

		Machine* the_machine;
		MACHINE_TYPE mtype;

		if (type == "Treadmill") 
			mtype = TREADMILL;
		else if (type == "Squat Rack")
			mtype = SQUAT_RACK;
		else if (type == "Bike")
			mtype = BIKE;

		the_machine = theMachineFactory->createMachine(mtype);
		the_machine->changeName(name, false);
		machineArray[front] = the_machine;

		front++;
	}

	cout << "done loading.\n";
	loadF.close();
	return front;
}


int main() {
	// create a new machine factory to create new machines from
	MachineFactory* theMachineFactory = new MachineFactory();
	string inStr;
	// array to hold machines currently allows for 64
	Machine** machineArray = new Machine*[MAX_GYM_SIZE];
	// inistialize array index and load in machines from previous runs of the program
	int front = load(machineArray, theMachineFactory); // front keeps track of the index where the next element needs to be inserted

	// main program logic
	while (inStr != "q") {

		cout << "would you like to create a new machine (c)? Print the list of machines (p)? or Quit (q)? ";
		cin >> inStr;

		if (inStr == "c") {
			string newName, selection;
			Machine* new_machine;
			MACHINE_TYPE type;

			selection = INVALID_SELECTION;
			// if the selection was valid
			while (selection == INVALID_SELECTION) {
				cout << "Would you like to create a Treadmill (t), Bike (b) or Squat Rack (s)?";
				cin >> selection;
				if (selection == "t") type = TREADMILL;
				else if (selection == "b") type = BIKE;
				else if (selection == "s") type = SQUAT_RACK;
				else {
					cout << selection << " is an invalid command please try again" << endl;
					selection = INVALID_SELECTION;
				}
			}
			// this is where a new machine is created from cloning a prototype in
			// machineFactory
			new_machine = theMachineFactory->createMachine(type);
			cout << "Machine created" << endl;
			cout << "what would you like to name the Machine?" << endl << "name: ";
			cin.ignore(2, '\n'); // removes the /n char from earlier from the input buffer
			getline(cin, newName);
			// changes the name of the machine that the prototype had to somthing
			// the user specifys
			new_machine->changeName(newName, true);
			machineArray[front] = new_machine;
			front++;

		} else if (inStr == "q") {
			// saves the classes in savestate.txt
			// before quitting
			save(machineArray,front);
			cout << "quiting" << endl;

		} else if (inStr == "p") {
			cout << "here is a list of machines: " << endl;
			for (int m = 0; m < front; m++)
				cout << machineArray[m]->print() << endl;

		} else {
			cout << inStr << " is an invalid command please try again" << endl;
		}
	}

	return 0;
}

