#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include <iostream>

typedef void (*TestFunc)(void);

class TestCase
{
public:
	TestCase(std::string name, TestFunc func);	// Constructeur avec paramètres
	TestCase(const TestCase &other);			// Constructeur de recopie
	~TestCase();								// Destructeur éventuellement virtuel
	TestCase &operator=(const TestCase &other); // Opérateur d'affectation
	bool run();									// Méthode pour exécuter le test
	std::string getName() const;				// Méthode pour obtenir le nom du test
	TestFunc getFunc() const;					// Méthode pour obtenir la fonction de test
	size_t getCount() const;					// Méthode pour obtenir le compteur d'exécutions
	size_t getSuccess() const;					// Méthode pour obtenir le compteur de succès
	std::string getError() const;				// Méthode pour obtenir le message d'erreur

private:
	std::string _name;	// Nom du test
	TestFunc _func;		// Fonction de test
	size_t _count;		// Compteur d'exécutions
	size_t _success;	// Compteur de succès
	std::string _error; // Message d'erreur en cas d'échec
};

#endif // TESTCASE_HPP