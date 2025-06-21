#include "cppUnit52.hpp"

void testFunction1()
{
	EXPECT(0).toBe(0);
	EXPECT(0).toBe(-1);
}

void testFunction2()
{
	EXPECT(4).toBe(4);
	EXPECT(2).toBe(2);
}

void testFunction3()
{
	EXPECT(1).toBe(3);
	EXPECT(1).toBe(1);
	EXPECT(10).toBe(10);
}

void testFunction4()
{
	EXPECT(5).toBe(5);
}

int main(int argc, char const *argv[])
{
	Tester::init(argc, argv);

	DESCRIBE("Group 1")
	{
		IT("Test 1.1", testFunction1);
		IT("Test 1.2", testFunction2);
	}
	DESCRIBE("Group 2")
	{
		IT("Test 2.1", testFunction3);
		IT("Test 2.2", testFunction4);
	}
	return (Tester::run());
}
