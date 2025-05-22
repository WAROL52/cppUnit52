#ifndef EXPECT_HPP
# define EXPECT_HPP

# include <iostream>

template <typename T>
class Expect
{
	/* 
	** Intern Class	: NotProxy
	** Description	:
	**		la class proxy permet en quelques sorte de definir une action 
	**		au moment de l'appel d'un attribut membre.
	** Utility		:
	**		Enchainement dans l'appel de la variable assignee a elle.
	** Use case		:
	**	```
	**		int	test(1 + 2)
	**		Expect<int> expect;
	**		expect(test).Not->toBe(4);
	**	```
	** Limitation in implemention of NotProxy class	:
	**		Malheureusement, il est impossible de surcharger l'[operator.]
	**		du coup l'ecriture se fait aver la notation flechee (->) au lieu
	**		d'un simple point (.).
	 */

	class NotProxy
	{
		private:
			Expect<T>	*_att;

			NotProxy(void) {}
			NotProxy(NotProxy const &_) { (void)_; }
			void	operator=(Expect<T> const &_) { (void)_; }
		public:
			NotProxy(Expect<T> *att) : _att(att) {}
			Expect<T>	*operator->(void) {
				this->_att->_inverse_condition = !this->_att->_inverse_condition;
				return (this->_att);
			}
	};

	public:
		NotProxy	Not;
		
		Expect();									// Constructeur par défaut
		Expect(T &value);							// Constructeur par défaut
		Expect(const Expect &);						// Constructeur de recopie
		virtual ~Expect();							// Destructeur éventuellement virtuel
		
		Expect		&operator=(const Expect &);		// Operator d'affectation
		Expect<T>	&operator()(T const &vref);		// Operator d'affectation
		Expect<T>	&operator!(void);				// Operator d'inversion
		
		Expect<T>	&toBe(T const &value);
		T const		&getValue(void) const;

	private:
		T		_value;
		bool	_inverse_condition;
	// Membres privés
};

# include "Expect.tpp"

#endif // EXPECT_HPP