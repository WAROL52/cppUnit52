#ifndef PROXY_HPP
# define PROXY_HPP

template <typename T>
class Proxy
{
	protected:
		T		*_att;
		void	(*action)(T *att);

		Proxy(void) {}
		Proxy(Proxy const &_) { (void)_; }
		void	operator=(T const &_) { (void)_; }
	
	public:

		Proxy(T *att, void (*func)(T *att)) : _att(att), action(func) {}
		void init(T *att, void (*func)(T *att))
		{
			this->_att = att;
			this->action = func;
		}
		T	*operator->(void)
		{
			Proxy::action(this->_att);
			return (this->_att);
		}
};

#endif