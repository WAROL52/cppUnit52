#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
template <typename T>
struct Node
{
	T data;				// Donnée stockée dans le nœud
	Node *next;			// Pointeur vers le nœud suivant
	Node(const T &item) // Constructeur pour initialiser le nœud avec une donnée
		: data(item), next(NULL)
	{
	}
};

template <typename T>
class List
{
public:
	List();									 // Constructeur par défaut
	List(const List<T> &);					 // Constructeur de recopie
	~List();								 // Destructeur éventuellement virtuel
	List &operator=(const List<T> &);		 // Operator d'affectation
	T &add(const T &item);					 // Méthode pour ajouter un élément à la liste
	void remove(const T &item);				 // Méthode pour supprimer un élément de la liste
	bool contains(const T &item) const;		 // Méthode pour vérifier si un élément est dans la liste
	size_t size() const;					 // Méthode pour obtenir la taille de la liste
	T &operator[](size_t index);			 // Opérateur d'indexation pour accéder à un élément
	const T &operator[](size_t index) const; // Opérateur d'indexation pour accéder à un élément (const)
	void clear();							 // Méthode pour vider la liste
	class Iterator
	{
	public:
		Iterator(Node<T> *node);					  // Constructeur de l'itérateur
		bool operator!=(const Iterator &other) const; // Comparaison d'itérateurs
		T &operator*();								  // Déréférencement de l'itérateur
		Iterator &operator++();						  // Incrémentation de l'itérateur
		const T &operator*() const;					  // Déréférencement de l'itérateur (const)
		Iterator(const Iterator &other);			  // Constructeur de recopie de l'itérateur
		Iterator &operator=(const Iterator &other);	  // Opérateur d'affectation de l'itérateur
		~Iterator();								  // Destructeur de l'itérateur
		bool operator==(const Iterator &other) const; // Comparaison d'itérateurs pour égalité
		Iterator &operator--();						  // Décrémentation de l'itérateur
		Iterator operator++(int);					  // Incrémentation postfixée de l'itérateur
		Iterator operator--(int);					  // Décrémentation postfixée de l'itérateur
		Iterator next() const;						  // Méthode pour obtenir l'itérateur suivant
		Iterator previous() const;					  // Méthode pour obtenir l'itérateur précédent
		bool isEnd() const;							  // Méthode pour vérifier si l'itérateur est à la fin
		bool isBegin() const;						  // Méthode pour vérifier si l'itérateur est au début
		Node<T> *getNode() const;					  // Méthode pour obtenir le nœud courant de l'itérateur
		void setNode(Node<T> *node);				  // Méthode pour définir le nœud courant de l'itérateur
	private:
		Node<T> *current; // Pointeur vers le nœud courant de l'itérateur
	};
	Iterator begin() const; // Méthode pour obtenir l'itérateur de début
	Iterator end() const;	// Méthode pour obtenir l'itérateur de fin
	void print() const;		// Méthode pour afficher les éléments de la liste
private:
	Node<T> *head; // Pointeur vers le premier nœud de la liste
	size_t count;  // Compteur d'éléments dans la liste
};

#include "List.tpp"

#endif // LIST_HPP