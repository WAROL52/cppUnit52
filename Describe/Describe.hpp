#ifndef DESCRIBE_HPP
#define DESCRIBE_HPP

#include <iostream>
#include "../Expect/Expect.hpp"

class Describe
{
public:
	Describe(std::string name);			   // Constructeur par défaut
	Describe(const Describe &);			   // Constructeur de recopie
	~Describe();						   // Destructeur éventuellement virtuel
	Describe &operator=(const Describe &); // Operator d'affectation
	Describe &test(std::string name, void (*)(Expect<int> &expect));
	void run();

private:
	// Membres privés
	std::string name;
	Expect<int> expect;
};

#endif // DESCRIBE_HPP