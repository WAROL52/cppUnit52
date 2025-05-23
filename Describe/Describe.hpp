#ifndef DESCRIBE_HPP
# define DESCRIBE_HPP

# include <iostream>
# include "../Expect/Expect.hpp"
# include "../List/List.hpp"

class Describe
{
	public:
		Describe(std::string name);			   // Constructeur par défaut
		Describe(const Describe &);			   // Constructeur de recopie
		~Describe();						   // Destructeur éventuellement virtuel
		Describe &operator=(const Describe &); // Operator d'affectation
		template <typename T>
		Describe &test(std::string name, void (*)(Expect<T> &expect));
		void run();

	private:
		// Membres privés
		std::string	name;
		Expect<int>	expect;

		// template <typename T>
		// List<T>		_test_list;
};

# include "Describe.tpp"

#endif // DESCRIBE_HPP