#include "List.hpp"
#include "List.hpp"

template <typename T>
List<T>::List() : head(0), count(0) {}

template <typename T>
List<T>::List(const List<T> &other) : head(0), count(0)
{
	Node *current(other.head);

	if (this->count)
		this->clear();
	while (current)
	{
		push_back(current->data);
		current = current->next;
	}
}

template <typename T>
List<T>::~List()
{
	this->clear();
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &other)
{
	if (this != &other)
	{
		clear();
		Node *current = other.head;
		while (current)
		{
			push_back(current->data);
			current = current->next;
		}
	}
	return *this;
}

template <typename T>
void List<T>::push_front(const T &value)
{
	Node *newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	++count;
}

template <typename T>
void List<T>::push_back(const T &value)
{
	Node *newNode = new Node(value);
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node *curr = head;
		while (curr->next)
			curr = curr->next;
		curr->next = newNode;
	}
	++count;
}

template <typename T>
void List<T>::pop_front()
{
	if (!head)
		return;
	Node *tmp = head;
	head = head->next;
	delete tmp;
	--count;
}

template <typename T>
void List<T>::clear()
{
	while (head)
		pop_front();
}

template <typename T>
int List<T>::size() const
{
	return count;
}

template <typename T>
void List<T>::print() const
{
	Node *curr = head;
	while (curr)
	{
		std::cout << curr->data << " -> ";
		curr = curr->next;
	}
	std::cout << "NULL" << std::endl;
}

template <typename T>
void List<T>::forEach(void (*func)(T &))
{
	Node *current = head;
	while (current)
	{
		func(current->data);
		current = current->next;
	}
}