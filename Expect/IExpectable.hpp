#ifndef IEXPECTABLE_HPP
#define IEXPECTABLE_HPP

#include <iostream>

template <typename T>
class IExpectable
{
public:
	typedef void (*Expector)(T &);
	virtual ~IExpectable() {}; // Destructeur éventuellement virtuel
	virtual IExpectable<T> &toBe(const &, line = __LINE__);
	virtual IExpectable<T> &toBeNull(const &);
	virtual IExpectable<T> &toBeTruthy(const &);
	virtual IExpectable<T> &toBeFalsy(const &);
	virtual IExpectable<T> &toBeGT(const &);
	virtual IExpectable<T> &toBeGTE(const &);
	virtual IExpectable<T> &toBeLT(const &);
	virtual IExpectable<T> &toBeLTE(const &);
	virtual IExpectable<T> &to(Expector);
};

#endif // IEXPECTABLE_HPP