#ifndef LOG_HPP
# define LOG_HPP

# include <string>
# include <iostream>

class Log
{
	private:
		Log(void);
		Log(Log const &_);
		~Log(void);
		Log	&operator=(Log const &_);
	
	public:
		static std::string	color_level[2][2][2];
		static void show(bool status, std::string const &label, int level = 0);
};

#endif 	