#include "Log.hpp"
#include <iostream>

Log::Log(void) {}
Log::Log(Log const &_) { (void)_; }
Log::~Log(void) {}
Log	&Log::operator=(Log const &_)
{
	(void)_;
	return (*this);
}

void	Log::show(bool status, std::string const &label, int level)
{
	std::cout
		<< Log::color_level[level][status][0]
		<< Log::color_level[level][status][1]
		<< "\e[0m "
		<< "  "
		<< (level ? "" : "\e[4;30m") << label
		<< "\e[0m  "
		<< std::endl;
}

std::string	Log::color_level[2][2][2] = {
	{{"\e[0;101m", " FAIL "}, {"\e[0;102m", " PASS "}},
	{{"\e[0;91m", " ✕ "}, {"\e[0;92m", " ✓ "}}
};
