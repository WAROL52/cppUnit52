#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include "../utilities/Iterator/Iterator.hpp"

template <typename T>
class List
{
	private:
		Node<T>		*head;
		Iterator<T>	_iterator;
		int count;
	
	public:
		List();									// Constructeur par défaut
		List(const List<T> &);					// Constructeur de recopie
		~List();								// Destructeur éventuellement virtuel
		List<T>	&operator=(const List<T> &);	// Operator d'affectation

		void			push_front(const T &value);
		void			push_back(const T &value);
		void			pop_front();
		void			forEach(void (*func)(T &));
		void			clear();
		int				size() const;
		void			print() const;
		Iterator<T>		&begin(void);
};

# include "List.tpp"

#endif // LIST_HPP