#ifndef DESCRIBE_HPP
# define DESCRIBE_HPP

# include "../Expect/Expect.hpp"
# include "../List/List.hpp"
# include "../utilities/Log/Log.hpp"
# include <iostream>
# include <string>

typedef unsigned int	uint;

template <typename T>
struct Test
{
	std::string const	label;
	bool				status;
	void				(*func)(Expect<T> &);
	
	Test(std::string const &label, void (*func)(Expect<T> &)) :
		label(label),
		status(false),
		func(func)
	{}
};

class Describe
{
	public:
		Describe(std::string name);				// Constructeur par défaut
		Describe(const Describe &);				// Constructeur de recopie
		~Describe();							// Destructeur éventuellement virtuel
		Describe	&operator=(const Describe &);	// Operator d'affectation
		template <typename T>
		Describe	&test(std::string name, void (*)(Expect<T> &expect));
		template <typename T>
		void		run();

	private:
		std::string	name;
		Expect<int>	expect;
		void		*_test_list;
		uint		_nb_test;
		uint		_nb_test_per_expect;
};

# include "Describe.tpp"

#endif // DESCRIBE_HPP