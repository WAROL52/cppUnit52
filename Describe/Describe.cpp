#include "Describe.hpp"

Describe::Describe(std::string name)
{ // Constructeur par défaut
	this->name = name;
}

Describe::Describe(const Describe &other)
{ // Constructeur de recopie
}

Describe::~Describe()
{ // Destructeur éventuellement virtuel
}

Describe &Describe::operator=(const Describe &other)
{ // Operator d'affectation
	return (*this);
}

Describe &Describe::test(std::string name)
{
	return (*this);
}