#include "Expect.hpp"

template <typename T>
Expect<T>::Expect(T &valueRef) : valueRef(valueRef) {}

template <typename T>
Expect<T>::Expect(const Expect &other) : valueRef(other.valueRef) {}

template <typename T>
Expect<T>::~Expect()
{ // Destructeur éventuellement virtuel
}

template <typename T>
Expect<T> &Expect<T>::operator=(const Expect &other)
{ // Operator d'affectation
	return (*this);
}
