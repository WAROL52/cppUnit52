#ifndef EXPECT_HPP
#define EXPECT_HPP

#include <iostream>

template <typename T>
class Expect
{
public:
	Expect(const T &value);			   // Constructeur par défaut
	Expect(const Expect &);			   // Constructeur de recopie
	~Expect();						   // Destructeur éventuellement virtuel
	Expect &operator=(const Expect &); // Operator d'affectation

private:
	const T &valueRef;
};

#endif // EXPECT_HPP