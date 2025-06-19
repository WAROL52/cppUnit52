#include "cppUnit52.hpp"

#define V(v) (v), (__LINE__)

void bombazy(int age, int line)
{
	std::cout << "LINE:" << line << std::endl;
	std::cout << "__FUNCTION__:" << __FUNCTION__ << std::endl;
	std::cout << "__PRETTY_FUNCTION__:" << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "age:" << age << std::endl;
}

// Crée un bloc pour un groupe
#define DESCRIBE(name)                   \
	for (bool _g = true; _g; _g = false) \
		for (TestGroup &_group = Tester::group(name); _g; _g = false)

// Ajoute un test dans le groupe courant
#define IT(testName, func) _group.addTest(testName, func)

class Expectation
{
	int _actual;
	const char *_func;
	const char *_file;
	int _line;

public:
	Expectation(int actual, const char *func, const char *file, int line)
		: _actual(actual), _func(func), _file(file), _line(line) {}

	void toBe(int expected) const
	{
		if (_actual == expected)
		{
			std::cout
				<< " [✓] "
				<< _func
				<< " ("
				<< _file << ":" << _line << ") "
				<< _actual << " == " << expected
				<< std::endl;
		}
		else
		{
			std::cout << "  [✗] " << _actual << " != " << expected
					  << " (" << _func << ")\n"
					  << "      dans " << _file << ":" << _line << "\n";
		}
	}
};

// Macro qui masque les infos automatiquement
#define EXPECT(val) Expectation(val, __PRETTY_FUNCTION__, __FILE__, __LINE__)

void testFunction1()
{
	EXPECT(0).toBe(-1);
}

void testFunction2()
{
	EXPECT(4).toBe(4);
	EXPECT(2).toBe(2);
}

void testFunction3()
{
	EXPECT(1).toBe(3);
}

void testFunction4()
{
	EXPECT(5).toBe(5);
}

int main(int argc, char const *argv[])
{
	Tester::init(argc, argv);

	// TestGroup &group1 = Tester::group("Group 1");

	// TestGroup &group2 = Tester::group("Group 2");

	// group1.addTest("Test 1.1", testFunction1);
	// group1.addTest("Test 1.2", testFunction2);

	// group2.addTest("Test 2.1", testFunction3);
	// group2.addTest("Test 2.2", testFunction4);

	DESCRIBE("Group 1")
	{
		IT("Test 1.1", testFunction1);
		IT("Test 1.2", testFunction2);
	}
	DESCRIBE("Group 2")
	{
		IT("Test 2.1", testFunction3);
		IT("Test 2.2", testFunction4);
	}

	return (Tester::run());
}
