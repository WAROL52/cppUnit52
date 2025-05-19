#include "Tester.hpp"

Tester::Tester(int argc, char **argv)
{
	this->argc = argc;
	this->argv = argv;
}

Tester::Tester(const Tester &other)
{
	this->describeList = other.describeList;
	this->argc = other.argc;
	this->argv = other.argv;
}

Tester::~Tester()
{
	this->describeList.clear();
}

Tester &Tester::operator=(const Tester &other)
{
	if (this != &other)
	{
		this->describeList = other.describeList;
		this->argc = other.argc;
		this->argv = other.argv;
	}
	return (*this);
}

void runOne(Describe &describe)
{
	describe.run();
}

int Tester::run()
{
	this->describeList.forEach(runOne);
	return (0);
}