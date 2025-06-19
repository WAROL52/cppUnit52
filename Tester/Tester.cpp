#include "Tester.hpp"

// [Forme canonique] Implémentation de la classe Tester
Tester *Tester::_instance = NULL;
void Tester::init(int argc, const char **argv)
{ // Méthode pour initialiser le testeur
	if (_instance == NULL)
	{
		_instance = new Tester(argc, argv);
	}
}

Tester::Tester(int argc, char const *argv[])
	: _testGroupList()
{ // Constructeur avec paramètres

	_testConfig._argc = argc;
	_testConfig._argv = argv;
}

Tester::~Tester()
{ // Destructeur éventuellement virtuel
	_testGroupList.clear();
}

// [Fin de la forme canonique] ==============================

TestGroup &Tester::addGroup(const TestGroup &testGroup)
{
	return _instance->_testGroupList.add(testGroup);
}

int Tester::run()
{ // Méthode pour exécuter tous les tests
	Tester *tester = Tester::_instance;
	int totalSuccess = 0;
	if (tester == NULL)
		return 1;
	std::cout << "🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n";
	for (size_t i = 0; i < tester->_testGroupList.size(); ++i)
	{
		TestGroup &group = tester->_testGroupList[i];
		int groupSuccess = group.runTests();
		totalSuccess += groupSuccess;
		// group.printResults();
	}
	std::cout << "🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱\n";

	if (_instance != NULL)
	{
		delete _instance; // Libère l'instance du testeur
		_instance = NULL; // Réinitialise le pointeur à NULL
	}
	return totalSuccess == 0 ? 0 : 1; // Retourne 0 si tous les tests ont réussi, sinon 1
}
bool Tester::hasInstance()
{
	return (!!_instance);
}

TestGroup &Tester::group(const char *name)
{
	return group(std::string(name));
}

TestGroup &Tester::group(std::string name)
{
	TestGroup &g = addGroup(TestGroup(name));
	return g;
}
