#ifndef EXPECTREF_HPP
#define EXPECTREF_HPP

#include <iostream>
#include "ExpectValue.hpp"
template <typename T>
class ExpectRef : public ExpectValue<T>
{
public:
	ExpectRef(const T &actual, const std::string &func, const std::string &file, const int line); // Constructeur par défaut
	ExpectRef(const ExpectRef &);																  // Constructeur de recopie
	~ExpectRef();																				  // Destructeur éventuellement virtuel
	ExpectRef &operator=(const ExpectRef &);													  // Operator d'affectation

private:
	T &_actual; // Référence à la valeur actuelle
				// Membres privés
};

#include "ExpectRef.tpp"

#endif // EXPECTREF_HPP