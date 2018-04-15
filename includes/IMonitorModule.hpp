#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include "../includes/mainHeader.hpp"

class IMonitorModule
{
	public:

		IMonitorModule(void);
		IMonitorModule(IMonitorModule const &obj);
		virtual ~IMonitorModule(void);
		IMonitorModule	&operator=(IMonitorModule const &rhs);

		virtual void							update(void) = 0;
		virtual std::vector<std::string> const	&getResult(void) const = 0;
		virtual std::string const				&getName(void) const = 0;
		
		
	

		
};

#endif