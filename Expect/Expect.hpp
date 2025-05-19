#ifndef EXPECT_HPP
#define EXPECT_HPP

#include <iostream>

template <typename T>
class Expect
{
public:
	Expect(T &valueRef);			   // Constructeur par défaut
	Expect(const Expect &);			   // Constructeur de recopie
	~Expect();						   // Destructeur éventuellement virtuel
	Expect &operator=(const Expect &); // Operator d'affectation

private:
	T &valueRef;
	// Membres privés
};

#endif // EXPECT_HPP