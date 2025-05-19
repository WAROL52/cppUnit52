#include "Describe.hpp"

Describe::Describe(std::string name)
{
	this->name = name;
}

Describe::Describe(const Describe &other)
{
	this->name = other.name;
	this->expect = other.expect;
}

Describe::~Describe()
{
}

Describe &Describe::operator=(const Describe &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->expect = other.expect;
	}
	return (*this);
}

Describe &Describe::test(std::string name, void (*func)(Expect<int> &expect))
{
	(void)name;
	(void)func;
	return (*this);
}

void Describe::run()
{
}