#include "Expect.hpp"

template <typename T>
Expect<T>::Expect(T &valueRef) : value(valueRef) {}

template <typename T>
Expect<T>::Expect()
{
	this->value = 0;
}

template <typename T>
Expect<T>::Expect(const Expect &other) : value(other.value) {}

template <typename T>
Expect<T>::~Expect()
{
}

template <typename T>
Expect<T> &Expect<T>::operator=(const Expect &other)
{
	return (*this);
}

template <typename T>
template <typename E>
Expect<E> &Expect<T>::operator()(E &vRef)
{
	return Expect<E>(vRef);
}

template <typename T>
Expect<T> &Expect<T>::toBe(const T &value)
{
	int result = this->value == value;
	(void)result;
	return (*this);
}