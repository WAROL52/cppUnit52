#ifndef PROXY_HPP
# define PROXY_HPP

template <typename T>
class Proxy
{
	protected:
		T	*_att;

		Proxy(void) {}
		Proxy(Proxy const &_) { (void)_; }
		void	operator=(T const &_) { (void)_; }
	
	public:
		Proxy(T *att) : _att(att) {}
		T	*operator->(void)
		{
			_att->proxyAction();
			return (this->_att);
		}
};

#endif