// unittest_A2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "Machine.h"
#include "Header1.h"
#include "MachineFactory.h"
using namespace std;

/*TEST(testTreadmill, treadmillPrintTest)
{	
	MachineFactory* theMachineFactory1 = new MachineFactory();
	Machine* new_machine1;
	new_machine1 = theMachineFactory1->createMachine(TREADMILL);
	EXPECT_EQ(new_machine1->print(), "Treadmill, name: Generic Treadmill Brand");
}*/

TEST(testadd1, isZero) {
	EXPECT_EQ(add1(0), 1);
}
TEST(testadd1, isNeg) {
	EXPECT_EQ(add1(-5), -4);
}
TEST(testadd1, isPos) {
	EXPECT_EQ(add1(30), 31);
}

TEST(testMul2, isZero) {
	EXPECT_EQ(multiply2(0), 0);
}
TEST(testMul2, isNeg) {
	EXPECT_EQ(multiply2(-10), -20);
}
TEST(testMul2, isPos) {
	EXPECT_EQ(multiply2(5), 10);
}

TEST(testSubtract3, isZero) {
	EXPECT_EQ(subtract3(0), -3);
}
TEST(testSubtract3, isNeg) {
	EXPECT_EQ(subtract3(-20), -23);
}
TEST(testSubtract3, isPos) {
	EXPECT_EQ(subtract3(89), 86);
}
