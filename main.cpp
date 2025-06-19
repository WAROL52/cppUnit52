#include "cppUnit52.hpp"

void testFunction1()
{
	std::cout << "Executing testFunction1" << std::endl;
}

void testFunction2()
{
	std::cout << "Executing testFunction2" << std::endl;
	throw std::runtime_error("An error occurred in testFunction2");
}

void testFunction3()
{
	std::cout << "Executing testFunction3" << std::endl;
}

void testFunction4()
{
	std::cout << "Executing testFunction4" << std::endl;
}

int main(int argc, char const *argv[])
{
	Tester::init(argc, argv);

	TestGroup &group1 = Tester::group("Group 1");

	TestGroup &group2 = Tester::group("Group 2");

	group1.addTest("Test 1.1", testFunction1);
	group1.addTest("Test 1.2", testFunction2);

	group2.addTest("Test 2.1", testFunction3);
	group2.addTest("Test 2.2", testFunction4);

	return (Tester::run());
}
