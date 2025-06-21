#ifndef EXPECTOR_HPP
#define EXPECTOR_HPP

#include <iostream>

template <typename T>
class Expector
{
public:
	typedef void (*Func)(const T &);
	Expector(const std::string &func, const std::string &file, const int line);
	Expector(const Expector &);			   // Constructeur de recopie
	Expector &operator=(const Expector &); // Operator d'affectation
	virtual ~Expector();				   // Destructeur éventuellement virtuel
	// -------------------------------------------
	virtual Expector<T> &toBe(const T &) = 0;
	virtual Expector<T> &toBeNull(const T &) = 0;
	virtual Expector<T> &toBeTruthy(const T &) = 0;
	virtual Expector<T> &toBeFalsy(const T &) = 0;
	virtual Expector<T> &toBeGT(const T &) = 0;
	virtual Expector<T> &toBeGTE(const T &) = 0;
	virtual Expector<T> &toBeLT(const T &) = 0;
	virtual Expector<T> &toBeLTE(const T &) = 0;
	virtual Expector<T> &to(Func) = 0;
	// -------------------------------------------
	static bool isEqual(const T &a, const T &b);
	static bool isNull(const T &a);
	static bool isTruthy(const T &a);
	static bool isFalsy(const T &a);
	static bool isGT(const T &a, const T &b);
	static bool isGTE(const T &a, const T &b);
	static bool isLT(const T &a, const T &b);
	static bool isLTE(const T &a, const T &b);
	static bool isSafeFunc(const T &a, Func func);
	static void printResult(const Expector &, const T &actual, const T &expected, bool passed);
	// -------------------------------------------
	static Expector<T> expect(const T &actual, const std::string &func, const std::string &file, int line);
	static Expector<T> expect(const T actual, const std::string &func, const std::string &file, int line);

private:
	// T _actual;		   // Valeur actuelle
	std::string _func; // Nom de la fonction
	std::string _file; // Nom du fichier
	int _line;		   // Numéro de ligne
};

#include "Expector.tpp"

#endif // EXPECTOR_HPP