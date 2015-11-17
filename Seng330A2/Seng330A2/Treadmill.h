#pragma once
#include "Machine.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <istream>
using namespace std;
/// Treadmill.
/// This is a derived class of Machine. 
/// It is used to create a new treadmill.

class Treadmill : public Machine
{

private:
	string name;
	string type;

public:
	Treadmill(string _name);
	Treadmill(const Treadmill& copy);
	~Treadmill();
	Machine* clone();
	string print();
	void changeName(string, bool);

};

