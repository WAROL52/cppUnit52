template <typename T>
Expect<T>::Expect(T &valueRef) 
: Not(this), _value(valueRef), _status(false), _inverse_condition(false) {}

template <typename T>
Expect<T>::Expect() : Not(this), _status(false), _inverse_condition(false)
{
	this->_value = 0;
}

template <typename T>
Expect<T>::Expect(const Expect &other)
 : Not(this), _value(other.value), _status(false), _inverse_condition(false) {}

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
Expect<T> &Expect<T>::toBe(T const &value)
{
	this->_status = this->_inverse_condition ?
		this->_value != value : this->_value == value;
	if (this->_status)
		std::cout << "Verified" << std::endl;
	else
		std::cout << "Error" << std::endl;
	return (*this);
}

template <typename T>
bool const	&Expect<T>::getStatus(void) const
{
	return (this->_status);
}
