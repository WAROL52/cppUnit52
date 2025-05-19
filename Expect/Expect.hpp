#ifndef EXPECT_HPP
#define EXPECT_HPP

#include <iostream>

template <typename T>
class Expect
{
public:
	Expect();						   // Constructeur par défaut
	Expect(T &value);				   // Constructeur par défaut
	Expect(const Expect &);			   // Constructeur de recopie
	~Expect();						   // Destructeur éventuellement virtuel
	Expect &operator=(const Expect &); // Operator d'affectation
	template <typename E>
	Expect<E> &operator()(E &vref); // Operator d'affectation
	Expect<T> &toBe(const T &value);

private:
	T &value;
	// Membres privés
};

#endif // EXPECT_HPP