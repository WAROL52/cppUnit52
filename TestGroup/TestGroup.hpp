#ifndef TESTGROUP_HPP
#define TESTGROUP_HPP

#include <iostream>
#include "../TestCase/TestCase.hpp"
#include "../List/List.hpp"

class TestGroup
{
public:
	TestGroup(const char *name);				   // Constructeur par défaut
	TestGroup(std::string name);				   // Constructeur par défaut
	TestGroup(const TestGroup &);				   // Constructeur de recopie
	~TestGroup();								   // Destructeur éventuellement virtuel
	TestGroup &operator=(const TestGroup &);	   // Operator d'affectation
	void addTest(std::string name, TestFunc func); // Méthode pour ajouter un cas de test
	int runTests();								   // Méthode pour exécuter tous les tests
	int runTest(size_t index);					   // Méthode pour exécuter un test
	int runTest(std::string name);				   // Méthode pour exécuter un test
	int runTest(TestFunc func);					   // Méthode pour exécuter un test
	void printResults() const;					   // Méthode pour afficher les résultats des tests
	void clear();								   // Méthode pour vider le groupe de tests
	std::string getName() const;				   // Méthode pour obtenir le nom du groupe de tests
	static TestGroup *getCurrentGroup();		   // Méthode statique pour obtenir le groupe de tests courant

private:
	// Membres privés
	static TestGroup *_currentGroup; // Pointeur vers le groupe de tests courant
	List<TestCase> _testCaseList;
	std::string _name;
};

#endif // TESTGROUP_HPP