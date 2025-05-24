#ifndef EXPECT_HPP
# define EXPECT_HPP

# include <iostream>
# include "../utilities/Proxy/Proxy.hpp"

typedef unsigned int	uint;

template <typename T>
class Expect
{
	private:
		T		_value;
		bool	_status;
		bool	_inverse_condition;
		uint	_nb_test;

	public:
		Proxy< Expect<T> >	Not;
		
		Expect();									// Constructeur par défaut
		Expect(T &value);							// Constructeur par défaut
		Expect(const Expect &);						// Constructeur de recopie
		virtual ~Expect();							// Destructeur éventuellement virtuel
		
		Expect		&operator=(const Expect &);		// Operator d'affectation
		Expect<T>	&operator()(T const &vref);		// Operator d'affectation
		Expect<T>	&operator!(void);				// Operator d'inversion
		
		uint		getNbTest(void) const;
		bool const	&getStatus(void) const;
		Expect<T>	&toBe(T const &value);

		static void	notProxyAction(Expect<T> *att);
};

# include "ProxyActions.tpp"
# include "Expect.tpp"

#endif // EXPECT_HPP