#ifndef Tester_HPP
#define Tester_HPP

#include <iostream>
#include "../TestGroup/TestGroup.hpp"
#include "../List/List.hpp"

struct TestConfig
{
	int _argc;
	const char **_argv;
};

class Tester
{
public:
	~Tester();												// Destructeur éventuellement virtuel
	static TestGroup &addGroup(const TestGroup &testGroup); // Méthode pour ajouter un groupe de tests
	static int run();										// Méthode pour exécuter tous les tests
	static void init(int argc, char const *argv[]);			// Méthode pour initialiser le testeur
	static const TestConfig &getConfig();					// Méthode pour obtenir la configuration du testeur
	static bool hasInstance();
	static TestGroup &group(const char *name);
	static TestGroup &group(std::string name);

private:
	Tester(int argc, char const *argv[]); // Constructeur avec paramètres
	List<TestGroup> _testGroupList;		  // Liste des groupes de tests
	TestConfig _testConfig;
	static Tester *_instance; // Instance unique du testeur
};

#endif // Tester_HPP