#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <typename T>
struct Node
{
	T		data;
	Node	*next;
	T		operator*(void) { return (data); }
	T		*operator->(void) { return (&data); }
	Node(const T &val) : data(val), next(0) {}
};

template <typename T>
class Iterator
{
	private:
		Node<T>	*_node;

	public:
		Iterator(void) : _node(NULL) {}
		Iterator(Iterator const &_) { *this = _; }
		Iterator(Node<T> *node) : _node(node) {}
		~Iterator(void) {}
		Iterator	&operator=(Iterator const &_);
		Iterator	&operator=(Node<T> *);
		operator	bool() const;
		Iterator	&operator++(void);
		Iterator	operator++(int);
		T			*operator->(void);
		T			operator*(void);
		T const		*operator->(void) const;
		T const		operator*(void) const;
};

# include "Iterator.tpp"

#endif