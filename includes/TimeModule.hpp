#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

#include "../includes/mainHeader.hpp"


class TimeModule : public IMonitorModule
{
	public:
		TimeModule(void);
		TimeModule(TimeModule const &obj);
		TimeModule	&operator=(TimeModule const &r);
		TimeModule(std::string const name);
		virtual ~TimeModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif
