#include "ExpectValue.hpp"

template <typename T>
ExpectValue<T>::ExpectValue(const T &actual, const std::string &func, const std::string &file, const int line)
	: Expector<T>(func, file, line), _actual(actual) {}

template <typename T>
ExpectValue<T>::ExpectValue(const ExpectValue &other)
	: Expector<T>(other), _actual(other._actual) {}

template <typename T>
ExpectValue<T>::~ExpectValue() {}

template <typename T>
ExpectValue<T> &ExpectValue<T>::operator=(const ExpectValue &other)
{
	if (this != &other)
	{
		Expector<T>::operator=(other);
		_actual = other._actual;
	}
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBe(const T &expected)
{
	bool passed = Expector<T>::isEqual(_actual, expected);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeNull(const T &expected)
{
	bool passed = Expector<T>::isNull(_actual);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeTruthy(const T &expected)
{
	bool passed = Expector<T>::isTruthy(_actual);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeFalsy(const T &expected)
{
	bool passed = Expector<T>::isFalsy(_actual);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeGT(const T &expected)
{
	bool passed = Expector<T>::isGT(_actual, expected);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeGTE(const T &expected)
{
	bool passed = Expector<T>::isGTE(_actual, expected);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeLT(const T &expected)
{
	bool passed = Expector<T>::isLT(_actual, expected);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::toBeLTE(const T &expected)
{
	bool passed = Expector<T>::isLTE(_actual, expected);
	Expector<T>::printResult(*this, _actual, expected, passed);
	return *this;
}

template <typename T>
ExpectValue<T> &ExpectValue<T>::to(typename Expector<T>::Func func)
{
	bool passed = Expector<T>::isSafeFunc(_actual, func);
	Expector<T>::printResult(*this, _actual, _actual, passed);
	return *this;
}
