#ifndef EXPECTVALUE_HPP
#define EXPECTVALUE_HPP

#include <iostream>
#include "Expector.hpp"

template <typename T>
class ExpectValue : public Expector<T>
{
public:
	ExpectValue(const T &actual, const std::string &func, const std::string &file, const int line); // Constructeur par défaut
	ExpectValue(const ExpectValue &);																// Constructeur de recopie
	virtual ~ExpectValue();																			// Destructeur éventuellement virtuel
	ExpectValue &operator=(const ExpectValue &);													// Operator d'affectation
	// -------------------------------------------
	ExpectValue &toBe(const T &expected);
	ExpectValue &toBeNull(const T &expected);
	ExpectValue &toBeTruthy(const T &expected);
	ExpectValue &toBeFalsy(const T &expected);
	ExpectValue &toBeGT(const T &expected);
	ExpectValue &toBeGTE(const T &expected);
	ExpectValue &toBeLT(const T &expected);
	ExpectValue &toBeLTE(const T &expected);
	ExpectValue &to(typename Expector<T>::Func func);
	// -------------------------------------------

private:
	T _actual; // Valeur actuelle
};
#include "ExpectValue.tpp"
#endif // EXPECTVALUE_HPP