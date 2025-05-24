template <typename T>
Expect<T>::Expect(T &valueRef) :
	_value(valueRef),
	_status(false),
	_inverse_condition(false),
	_nb_test(0),
	Not(this, Expect<T>::notProxyAction)
{}

template <typename T>
Expect<T>::Expect() :
	_value(0),
	_status(false),
	_inverse_condition(false),
	_nb_test(0),
	Not(this, Expect<T>::notProxyAction)
{}

template <typename T>
Expect<T>::Expect(const Expect &other) :
	_value(other._value),
	_status(other._status),
	_inverse_condition(other._inverse_condition),
	_nb_test(other._nb_test),
	Not(this, Expect<T>::notProxyAction)
{}

template <typename T>
Expect<T>::~Expect() {}

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
	this->_status = false;
	this->_inverse_condition = false;
	this->_nb_test = 0;
	this->Not.init(this, Expect<T>::notProxyAction);
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
	this->_nb_test++;
	return (*this);
}

template <typename T>
bool const	&Expect<T>::getStatus(void) const
{
	return (this->_status);
}

template <typename T>
uint 		Expect<T>::getNbTest(void) const
{
	return (this->_nb_test);
}


