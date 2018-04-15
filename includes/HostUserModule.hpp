#ifndef HOSTUSESMODULE_HPP
# define HOSTUSESMODULE_HPP

#include "../includes/mainHeader.hpp"


class HostUserModule : public IMonitorModule
{
	public:
		HostUserModule(void);
		HostUserModule(HostUserModule const &obj);
		HostUserModule	&operator=(HostUserModule const &r);
		HostUserModule(std::string const name);
		virtual ~HostUserModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif