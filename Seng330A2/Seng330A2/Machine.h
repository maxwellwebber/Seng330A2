#pragma once
#include <string>

using namespace std;
/// Machine. 
/// This is the base Prototype for all the
/// different types of machines.
class Machine
{
public:
	Machine();
	virtual ~Machine();
	virtual Machine* clone() = 0;
	virtual void print() = 0;
	virtual void changeName(string) = 0;
};
