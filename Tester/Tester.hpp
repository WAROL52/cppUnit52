#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>

class Tester
{
public:
	Tester();						   // Constructeur par défaut
	Tester(const Tester &);			   // Constructeur de recopie
	~Tester();						   // Destructeur éventuellement virtuel
	Tester &operator=(const Tester &); // Operator d'affectation

private:
	// Membres privés
};

#endif // TESTER_HPP