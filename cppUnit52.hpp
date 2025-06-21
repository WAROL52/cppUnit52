#ifndef CPPUNIT_HPP
#define CPPUNIT_HPP

#include <iostream>
#include "List/List.hpp"
#include "TestCase/TestCase.hpp"
#include "Tester/Tester.hpp"
#include "TestGroup/TestGroup.hpp"
#include "Expect/ExpectValue.hpp"
#include "Expect/ExpectRef.hpp"
#include "Expect/Expector.hpp"

template <typename T>
ExpectValue<T> expectValue(const T &actual, const std::string &func, const std::string &file, int line)
{
	return ExpectValue<T>(actual, func, file, line);
}

#define EXPECT(val) expectValue(val, __PRETTY_FUNCTION__, __FILE__, __LINE__)

// Crée un bloc pour un groupe
#define DESCRIBE(name)                   \
	for (bool _g = true; _g; _g = false) \
		for (TestGroup &_group = Tester::group(name); _g; _g = false)

// Ajoute un test dans le groupe courant
#define IT(testName, func) _group.addTest(testName, func)

#endif // CPPUNIT_HPP