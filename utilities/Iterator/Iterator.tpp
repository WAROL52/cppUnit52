template <typename T>
Iterator<T>	&Iterator<T>::operator=(Iterator<T> const &_)
{
	if (this != &_)
		this->_node = _._node;
	return (*this);
}

template <typename T>
Iterator<T>	&Iterator<T>::operator=(Node<T> *_)
{
	this->_node = _;
	return (*this);
}

template <typename T>
Iterator<T>::operator bool() const 
{
	return (this->_node != NULL);
}

template <typename T>
Iterator<T>	&Iterator<T>::operator++(void)
{
	if (this->_node)
		this->_node = this->_node->next;
	return (*this);
}

template <typename T>
Iterator<T>	Iterator<T>::operator++(int)
{
	Iterator<T>	tmp(*this);

	if (this->_node)
		this->_node = this->_node->next;
	return (tmp);
}

template <typename T>
T	*Iterator<T>::operator->(void)
{
	return (&this->_node->data);
}

template <typename T>
T	Iterator<T>::operator*(void)
{
	return (*this->_node);
}

template <typename T>
T const	*Iterator<T>::operator->(void) const
{
	return (&this->_node->data);
}

template <typename T>
T const	Iterator<T>::operator*(void) const
{
	return (*this->_node);
}
