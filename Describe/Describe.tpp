Describe::Describe(std::string name)
{
	this->name = name;
}

Describe::Describe(const Describe &other)
{
	this->name = other.name;
	this->expect = other.expect;
}

Describe::~Describe()
{
}

Describe &Describe::operator=(const Describe &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->expect = other.expect;
	}
	return (*this);
}

template <typename T>
Describe &Describe::test(std::string name, void (*func)(Expect<T> &expect))
{
	std::cout << "Name : " << name << std::endl;
	(*func)(this->expect);
	return (*this);
}

void Describe::run()
{
}