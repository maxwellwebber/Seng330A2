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

	MachineFactory* theMachineFactory = new MachineFactory();
	string inStr;
	Machine** machineArray = new Machine*[MAX_GYM_SIZE];
	int front = load(machineArray, theMachineFactory);

	while (inStr != "q") {

		cout << "would you like to create a new machine (c)? Print the list of machines (p)? or Quit (q)? ";
		cin >> inStr;



		if (inStr == "c") {
			string newName, selection;
			Machine* new_machine;
			MACHINE_TYPE type;

			selection = INVALID_SELECTION;
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

			new_machine = theMachineFactory->createMachine(type);
			cout << "Wachine created" << endl;
			cout << "what would you like to name the Machine?" << endl << "name: ";
			cin.ignore(2, '\n'); // removes the /n char from earlier from the input buffer
			getline(cin, newName);
			new_machine->changeName(newName, true);
			machineArray[front] = new_machine;
			front++;



		} else if (inStr == "q") {
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

