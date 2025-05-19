#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T>
class List
{
public:
	List();								 // Constructeur par défaut
	List(const List<T> &);				 // Constructeur de recopie
	~List();							 // Destructeur éventuellement virtuel
	List<T> &operator=(const List<T> &); // Operator d'affectation

	void push_front(const T &value);
	void push_back(const T &value);
	void pop_front();
	void forEach(void (*func)(T &));
	void clear();
	int size() const;
	void print() const;

private:
	struct Node
	{
		T data;
		Node *next;
		Node(const T &val) : data(val), next(0) {}
	};

	Node *head;
	int count;
};

#endif // LIST_HPP