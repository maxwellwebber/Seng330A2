#pragma once
#include "Machine.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <istream>
using namespace std;
/// Squat Rack.
/// This is a derived class of Machine. 
/// It is used to create a new Squat Rack.

class Squat_Rack : public Machine
{

private:
	string name;
	string type;

public:
	Squat_Rack(string _name);
	Squat_Rack(const Squat_Rack& copy);
	~Squat_Rack();
	Machine* clone();
	string print();
	void changeName(string, bool);

};

