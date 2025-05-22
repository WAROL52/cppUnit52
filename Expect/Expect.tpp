template <typename T>
Expect<T>::Expect(T &valueRef) : Not(this), _value(valueRef), _inverse_condition(false) {}

template <typename T>
Expect<T>::Expect() : Not(this), _inverse_condition(false)
{
	this->value = 0;
}

template <typename T>
Expect<T>::Expect(const Expect &other) : Not(this), _value(other.value), _inverse_condition(false) {}

template <typename T>
Expect<T>::~Expect()
{
}

template <typename T>
Expect<T> &Expect<T>::operator=(const Expect &other)
{
	(void)other;
	return (*this);
}

template <typename T>
Expect<T> &Expect<T>::operator()(T const &vRef)
{
	this->_value = vRef;
	return (*this);
}

template <typename T>
Expect<T> &Expect<T>::operator!(void)
{
	this->_inverse_condition = !this->_inverse_condition;
	return (*this);
}

template <typename T>
T const	&Expect<T>::getValue(void) const
{
	return (this->value);
}

template <typename T>
Expect<T> &Expect<T>::toBe(T const &value)
{
	int result = (
		this->_inverse_condition ?
			this->_value != value : this->_value == value);
	if (result)
		std::cout << "Verified" << std::endl;
	else
		std::cout << "Error" << std::endl;
	(void)result;
	return (*this);
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, Expect<T> const &_)
{
	o << _.getValue() << std::endl;
	return (o);
}