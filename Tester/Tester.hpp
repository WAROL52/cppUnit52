#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include "../Describe/Describe.hpp"
#include "../List/List.hpp"

class Tester
{
public:
	Tester(int argc, char **argv);	   // Constructeur par défaut
	Tester(const Tester &);			   // Constructeur de recopie
	~Tester();						   // Destructeur éventuellement virtuel
	Tester &operator=(const Tester &); // Operator d'affectation
	Describe &describe(std::string name);
	int run();

private:
	List<Describe> describeList;
	int argc;
	char **argv;
};

#endif // TESTER_HPP