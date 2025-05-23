Describe::Describe(std::string name)
{
	this->name = name;
	this->_test_list = NULL;
}

Describe::Describe(const Describe &other)
{
	this->name = other.name;
	this->expect = other.expect;
	this->_test_list = NULL;
}

Describe::~Describe(void)
{
}

Describe &Describe::operator=(const Describe &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->expect = other.expect;
		this->_test_list = other._test_list;
	}
	return (*this);
}

template <typename T>
Describe &Describe::test(std::string name, void (*func)(Expect<T> &expect))
{
	List< Test<T> >	*list;
	Test<T>			test(name, func);

	if (this->_test_list)
		list = static_cast< List< Test<T> > * >(this->_test_list);
	else
	{
		list = new List< Test<T> >();
		this->_test_list = static_cast<void *>(list);
	}
	list->push_back(test);
	return (*this);
}

template <typename T>
void Describe::run()
{
	List< Test<T> >		*list(static_cast< List< Test<T> > * >(this->_test_list));
	Iterator< Test<T> >	it(list->begin());

	while (it)
	{
		it->func(this->expect);
		it->status = this->expect.getStatus();
		Log::show(it->status, it->label, 1);
		this->_nb_test_per_expect += this->expect.getNbTest();
		this->_nb_test++;
		it++;
	}
}
