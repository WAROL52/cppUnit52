template <typename T>
void	Expect<T>::notProxyAction(Expect<T> *att)
{
	att->_inverse_condition = !att->_inverse_condition;
}
