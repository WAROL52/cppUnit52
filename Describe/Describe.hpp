#ifndef DESCRIBE_HPP
#define DESCRIBE_HPP

#include <iostream>

class Describe
{
public:
	Describe(std::string name);			   // Constructeur par défaut
	Describe(const Describe &);			   // Constructeur de recopie
	~Describe();						   // Destructeur éventuellement virtuel
	Describe &operator=(const Describe &); // Operator d'affectation
	Describe &test(std::string name);

private:
	// Membres privés
	std::string name;
};

#endif // DESCRIBE_HPP