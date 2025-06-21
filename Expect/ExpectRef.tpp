#include "ExpectRef.hpp"

template <typename T>
ExpectRef<T>::ExpectRef(const T &actual, const std::string &func, const std::string &file, const int line)
	: ExpectValue<T>(actual, func, file, line), _actual(actual) {}

template <typename T>
ExpectRef<T>::ExpectRef(const ExpectRef &other)
	: ExpectValue<T>(other), _actual(other._actual) {}

template <typename T>
ExpectRef<T>::~ExpectRef() {}

template <typename T>
ExpectRef<T> &ExpectRef<T>::operator=(const ExpectRef &other)
{
	if (this != &other)
	{
		ExpectValue<T>::operator=(other);
		_actual = other._actual;
	}
	return *this;
}
