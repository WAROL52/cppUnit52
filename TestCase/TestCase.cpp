#include "TestCase.hpp"

// [Forme canonique] Implémentation de la classe TestCase

TestCase::TestCase(std::string name, TestFunc func)
	: _name(name), _func(func), _count(0), _success(0), _error("")
{ // Constructeur avec paramètres
}

TestCase::TestCase(const TestCase &other)
	: _name(other._name), _func(other._func), _count(0), _success(0), _error("")
{				   // Constructeur de recopie
	*this = other; // Appel de l'opérateur d'affectation
}

TestCase::~TestCase()
{ // Destructeur éventuellement virtuel
}

TestCase &TestCase::operator=(const TestCase &other)
{ // Opérateur d'affectation
	if (this != &other)
	{
		_name = other._name;
		_func = other._func;
		_count = other._count;
		_success = other._success;
		_error = other._error;
	}
	return (*this);
}
// [Fin de la forme canonique] ==============================
#include <iostream>
#include <fstream>
#include <unistd.h> // sleep()
#include <cstdio>	// remove()
#include <sstream>	// stringstream
bool TestCase::run()
{
	if (_func)
	{
		this->_count++;
		this->_success++;
		this->_error.clear();

		// 🔵 Affiche le nom du test en gris
		std::cout << "   🔵 \033[30m" << _name << "\033[0m ";
		std::cout.flush(); // Assure que le texte est affiché immédiatement
		sleep(1);		   // Pause de 3 secondes pour la lisibilité
		// 📦 Capture cout dans un stringstream
		std::streambuf *coutbuf = std::cout.rdbuf();
		std::ostringstream capture;
		std::cout.rdbuf(capture.rdbuf());

		bool success = true;

		try
		{
			std::cout << "\033[0m ";
			std::cout.flush(); // Assure que le texte est affiché immédiatement
			_func();		   // exécute la fonction de test
		}
		catch (const std::exception &e)
		{
			this->_success--;
			this->_error = e.what();
			success = false;
		}

		// ✅❌ Affiche le résultat
		std::cout.rdbuf(coutbuf); // restaure cout

		if (success)
			std::cout << " ✅\033[0m" << std::endl;
		else
			std::cout << " ❌\033[0m" << std::endl;

		// 🧾 Affiche le contenu capturé
		std::string output = capture.str();
		if (!output.empty())
		{
			std::cout << "      \033[90m" << output << "\033[0m";
		}

		return success;
	}
	return false;
}

std::string TestCase::getName() const
{ // Méthode pour obtenir le nom du test
	return _name;
}

TestFunc TestCase::getFunc() const
{ // Méthode pour obtenir la fonction de test
	return _func;
}
size_t TestCase::getCount() const
{ // Méthode pour obtenir le compteur d'exécutions
	return _count;
}

size_t TestCase::getSuccess() const
{ // Méthode pour obtenir le compteur de succès
	return _success;
}

std::string TestCase::getError() const
{ // Méthode pour obtenir le message d'erreur
	return _error;
}