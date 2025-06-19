#include "../cppUnit52.hpp"

// [Forme canonique] Implémentation de la classe TestGroup

TestGroup::TestGroup(std::string name)
	: _testCaseList(), _name(name)
{
}
TestGroup::TestGroup(const char *name)
	: _testCaseList(), _name(name)
{
}
TestGroup::TestGroup(const TestGroup &other)
	: _testCaseList(other._testCaseList), _name(other._name)
{
	*this = other;
}

TestGroup::~TestGroup()
{ // Destructeur éventuellement virtuel
}

TestGroup &TestGroup::operator=(const TestGroup &other)
{ // Operator d'affectation
	if (this != &other)
	{
		_testCaseList = other._testCaseList;
	}
	return (*this);
}
// [Fin de la forme canonique] ==============================

std::string TestGroup::getName() const
{ // Méthode pour obtenir le nom du groupe de tests
	return _name;
}

void TestGroup::addTest(std::string name, TestFunc func)
{ // Méthode pour ajouter un cas de test
	_testCaseList.add(TestCase(name, func));
}

int TestGroup::runTests()
{
	std::cout << "📋 \033[1;34m" << _name << "\033[0m" << std::endl;
	int successCount = 0;
	for (List<TestCase>::Iterator it = _testCaseList.begin(); it != _testCaseList.end(); ++it)
	{
		TestCase &testCase = *it;
		if (testCase.run())
		{
			successCount++;
		}
		else
		{
			std::cerr << "Test failed: " << testCase.getName() << " - Error: " << testCase.getError() << std::endl;
		}
	}
	return successCount;
}

int TestGroup::runTest(size_t index)
{ // Méthode pour exécuter un test
	if (index < _testCaseList.size())
	{
		return _testCaseList[index].run() ? 1 : 0;
	}
	return -1; // Indique que l'index est hors limites
}

int TestGroup::runTest(std::string name)
{ // Méthode pour exécuter un test
	for (List<TestCase>::Iterator it = _testCaseList.begin(); it != _testCaseList.end(); ++it)
	{
		TestCase &testCase = *it;
		if (testCase.getName() == name)
		{
			return testCase.run() ? 1 : 0;
		}
	}
	return -1; // Indique que le test n'a pas été trouvé
}
int TestGroup::runTest(TestFunc func)
{ // Méthode pour exécuter un test
	for (List<TestCase>::Iterator it = _testCaseList.begin(); it != _testCaseList.end(); ++it)
	{
		TestCase &testCase = *it;
		if (testCase.getFunc() == func)
		{
			return testCase.run() ? 1 : 0;
		}
	}
	return -1; // Indique que le test n'a pas été trouvé
}
void TestGroup::printResults() const
{ // Méthode pour afficher les résultats des tests
	std::cout << "Test Results:" << std::endl;
	for (List<TestCase>::Iterator it = _testCaseList.begin(); it != _testCaseList.end(); ++it)
	{
		const TestCase &testCase = *it;
		std::cout << "Test: " << testCase.getName()
				  << " | Executions: " << testCase.getCount()
				  << " | Successes: " << testCase.getSuccess()
				  << " | Errors: " << testCase.getError() << std::endl;
	}
}

void TestGroup::clear()
{ // Méthode pour vider le groupe de tests
	_testCaseList.clear();
}