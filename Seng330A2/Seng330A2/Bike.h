#pragma once
#include "Machine.h"
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <istream>
using namespace std;
/// Bike.
/// This is a derived class of Machine. 
/// It is used to create a new Bike.

class Bike : public Machine
{

private:
	string name;

public:
	Bike(string _name);
	Bike(const Bike& copy);
	~Bike();
	Machine* clone();
	void print();
	void changeName(string);

};