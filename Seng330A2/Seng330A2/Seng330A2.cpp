#include <iostream>
#include <map>
#include <list>
#include <string>
#include <istream>

#include "stdafx.h"

#include "Machine.h"
#include "MachineFactory.h"


using namespace std;

const int MAX_GYM_SIZE = 64;
const string INVALID_SELECTION = "INVALID_STRING";




int main() {

	MachineFactory* theMachineFactory = new MachineFactory();
	string inStr;
	Machine** machineArray = new Machine*[MAX_GYM_SIZE];
	int front = 0;

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
			cout << "what would you like to name the Machine?" << endl << "name: ";
			cin.ignore(2, '\n'); // removes the /n char from earlier from the input buffer
			getline(cin, newName);
			new_machine->changeName(newName);
			machineArray[front] = new_machine;
			front++;

		} else if (inStr == "q") {
			cout << "quiting" << endl;

		} else if (inStr == "p") {
			cout << "here is a list of machines: " << endl;
			for (int m = front-1; m >= 0; m--)
				machineArray[m]->print();

		} else {
			cout << inStr << " is an invalid command please try again" << endl;
		}
	}

	return 0;
}

