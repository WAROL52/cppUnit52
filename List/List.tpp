#include "List.hpp"

// [Forme canonique] Implémentation de la classe List

template <typename T>
List<T>::List()
	: head(NULL), count(0)
{ // Constructeur par défaut
}

template <typename T>
List<T>::List(const List<T> &other)
	: head(NULL), count(0)
{ // Constructeur de recopie
	for (typename List<T>::Iterator it = other.begin(); it != other.end(); ++it)
	{
		add(*it);
	}
}

template <typename T>
List<T>::~List()
{ // Destructeur éventuellement virtuel
	clear();
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &other)
{ // Opérateur d'affectation
	if (this != &other)
	{
		clear();
		for (typename List<T>::Iterator it = other.begin(); it != other.end(); ++it)
		{
			add(*it);
		}
	}
	return *this;
}

template <typename T>
T &List<T>::add(const T &item)
{ // Méthode pour ajouter un élément à la liste
	Node<T> *newNode = new Node<T>(item);
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node<T> *current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	count++;
	return newNode->data; // Retourne une référence à l'élément ajouté
}

template <typename T>
void List<T>::remove(const T &item)
{ // Méthode pour supprimer un élément de la liste
	Node<T> *current = head;
	Node<T> *previous = NULL;

	while (current)
	{
		if (current->data == item)
		{
			if (previous)
			{
				previous->next = current->next;
			}
			else
			{
				head = current->next;
			}
			delete current;
			count--;
			return;
		}
		previous = current;
		current = current->next;
	}
}

template <typename T>
bool List<T>::contains(const T &item) const
{ // Méthode pour vérifier si un élément est dans la liste
	Node<T> *current = head;
	while (current)
	{
		if (current->data == item)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

template <typename T>
size_t List<T>::size() const
{ // Méthode pour obtenir la taille de la liste
	return count;
}

template <typename T>
T &List<T>::operator[](size_t index)
{ // Opérateur d'indexation pour accéder à un élément
	if (index >= count)
	{
		throw std::out_of_range("Index out of range");
	}
	Node<T> *current = head;
	for (size_t i = 0; i < index; ++i)
	{
		current = current->next;
	}
	return current->data;
}

template <typename T>
const T &List<T>::operator[](size_t index) const
{ // Opérateur d'indexation pour accéder à un élément (const)
	if (index >= count)
	{
		throw std::out_of_range("Index out of range");
	}
	Node<T> *current = head;
	for (size_t i = 0; i < index; ++i)
	{
		current = current->next;
	}
	return current->data;
}

template <typename T>
void List<T>::clear()
{ // Méthode pour vider la liste
	Node<T> *current = head;
	while (current)
	{
		Node<T> *nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = NULL;
	count = 0;
}

// [Fin de la forme canonique] ==============================

// fonction begin() et end() pour l'itérateur

template <typename T>
typename List<T>::Iterator List<T>::begin() const
{ // Méthode pour obtenir l'itérateur de début
	return Iterator(head);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const
{ // Méthode pour obtenir l'itérateur de fin
	return Iterator(NULL);
}

// [Forme canonique] Implémentation de la classe Iterator

template <typename T>
List<T>::Iterator::Iterator(Node<T> *node)
	: current(node)
{
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator &other) const
{ // Comparaison d'itérateurs
	return current != other.current;
}

template <typename T>
T &List<T>::Iterator::operator*()
{ // Déréférencement de l'itérateur
	if (!current)
	{
		throw std::out_of_range("Dereferencing end iterator");
	}
	return current->data;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator++()
{ // Incrémentation de l'itérateur
	if (current)
	{
		current = current->next;
	}
	return *this;
}

template <typename T>
const T &List<T>::Iterator::operator*() const
{ // Déréférencement de l'itérateur (const)
	if (!current)
	{
		throw std::out_of_range("Dereferencing end iterator");
	}
	return current->data;
}

template <typename T>
List<T>::Iterator::Iterator(const Iterator &other)
	: current(other.current)
{ // Constructeur de recopie de l'itérateur
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator=(const Iterator &other)
{ // Opérateur d'affectation de l'itérateur
	if (this != &other)
	{
		current = other.current;
	}
	return *this;
}

template <typename T>
List<T>::Iterator::~Iterator()
{ // Destructeur de l'itérateur
  // Pas de ressources à libérer, car l'itérateur ne possède pas le nœud
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator &other) const
{ // Comparaison d'itérateurs pour égalité
	return current == other.current;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator--()
{ // Décrémentation de l'itérateur
	if (!current)
	{
		throw std::out_of_range("Decrementing end iterator");
	}
	Node<T> *prev = NULL;
	Node<T> *temp = current;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
	}
	current = prev;
	return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{ // Incrémentation postfixée de l'itérateur
	Iterator temp = *this;
	++(*this);
	return temp;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--(int)
{ // Décrémentation postfixée de l'itérateur
	Iterator temp = *this;
	--(*this);
	return temp;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::next() const
{ // Méthode pour obtenir l'itérateur suivant
	if (!current)
	{
		throw std::out_of_range("Next on end iterator");
	}
	return Iterator(current->next);
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::previous() const
{ // Méthode pour obtenir l'itérateur précédent
	if (!current)
	{
		throw std::out_of_range("Previous on end iterator");
	}
	Node<T> *prev = NULL;
	Node<T> *temp = current;
	while (temp)
	{
		prev = temp;
		temp = temp->next;
	}
	return Iterator(prev);
}

template <typename T>
bool List<T>::Iterator::isEnd() const
{ // Méthode pour vérifier si l'itérateur est à la fin
	return current == NULL;
}

template <typename T>
bool List<T>::Iterator::isBegin() const
{ // Méthode pour vérifier si l'itérateur est au début
	return current != NULL && current->next == NULL;
}

template <typename T>
Node<T> *List<T>::Iterator::getNode() const
{ // Méthode pour obtenir le nœud courant de l'itérateur
	return current;
}

template <typename T>
void List<T>::Iterator::setNode(Node<T> *node)
{ // Méthode pour définir le nœud courant de l'itérateur
	current = node;
}

// [Fin de la forme canonique] ==============================

template <typename T>
void List<T>::print() const
{ // Méthode pour afficher les éléments de la liste
	std::cout << "[";
	Node<T> *current = head;
	while (current)
	{
		std::cout << current->data << (current->next ? ", " : "");
		current = current->next;
	}
	std::cout << "]" << std::endl;
}