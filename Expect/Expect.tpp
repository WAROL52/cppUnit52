#include "Expect.hpp"

// [Forme canonique] Implémentation de la classe Expect

template <typename T>
Expect<T>::Expect(const T &value)
	: valueRef(value)
{ // Constructeur par défaut
}

template <typename T>
Expect<T>::Expect(const Expect &other)
{ // Constructeur de recopie
}

template <typename T>
Expect<T>::~Expect()
{ // Destructeur éventuellement virtuel
}

template <typename T>
Expect<T> &Expect<T>::operator=(const Expect<T> &other)
{ // Operator d'affectation
	return (*this);
}
// [Fin de la forme canonique] ==============================