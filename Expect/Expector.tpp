#include "Expector.hpp"

// [Forme canonique] Implémentation de la classe Expector

template <typename T>
Expector<T>::Expector(const std::string &func, const std::string &file, const int line)
	: _func(func), _file(file), _line(line)
{ // Constructeur avec paramètres
}

template <typename T>
Expector<T>::Expector(const Expector &other)
	: _func(other._func), _file(other._file), _line(other._line)
{ // Constructeur de recopie
}

template <typename T>
Expector<T>::~Expector()
{ // Destructeur éventuellement virtuel
}

template <typename T>
Expector<T> &Expector<T>::operator=(const Expector &other)
{ // Operator d'affectation
	if (this != &other)
	{
		_func = other._func;
		_file = other._file;
		_line = other._line;
	}
	return (*this);
}
// [Fin de la forme canonique] ==============================

template <typename T>
bool Expector<T>::isEqual(const T &a, const T &b)
{
	return a == b;
}

template <typename T>
bool Expector<T>::isNull(const T &a)
{
	return a == 0;
}

template <typename T>
bool Expector<T>::isTruthy(const T &a)
{
	return !!a;
}

template <typename T>
bool Expector<T>::isFalsy(const T &a)
{
	return !a;
}

template <typename T>
bool Expector<T>::isGT(const T &a, const T &b)
{
	return a > b;
}

template <typename T>
bool Expector<T>::isGTE(const T &a, const T &b)
{
	return a >= b;
}

template <typename T>
bool Expector<T>::isLT(const T &a, const T &b)
{
	return a < b;
}

template <typename T>
bool Expector<T>::isLTE(const T &a, const T &b)
{
	return a <= b;
}

template <typename T>
bool Expector<T>::isSafeFunc(const T &a, Func func)
{
	try
	{
		func(a);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename T>
void Expector<T>::printResult(const Expector &expector, const T &actual, const T &expected, bool passed)
{
	if (passed)
	{
		std::cout
			<< "\t\033[32m[✓] \033[0m"
			<< expector._func
			<< " ("
			<< expector._file << ":" << expector._line << ") "
			<< actual << " == " << expected
			<< std::endl;
	}
	else
	{
		std::cout << "\t\033[7;31m[✗] "
				  << expector._func
				  << " ("
				  << expector._file << ":" << expector._line << ") "
				  << actual << " == " << expected << "\033[0m"
				  << std::endl;
	}
}

template <typename T>
Expector<T> Expector<T>::expect(const T &actual, const std::string &func, const std::string &file, int line)
{
	return ExpectValue(actual, func, file, line);
}

template <typename T>
Expector<T> Expector<T>::expect(const T actual, const std::string &func, const std::string &file, int line)
{
	return ExpectValue(actual, func, file, line);
}