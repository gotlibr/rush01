




#ifndef SYSTEMINFO_HPP
# define SYSTEMINFO_HPP

#include "../includes/mainHeader.hpp"


class SystemInfoModule : public IMonitorModule
{
	public:
		SystemInfoModule(void);
		SystemInfoModule(SystemInfoModule const &obj);
		SystemInfoModule	&operator=(SystemInfoModule const &r);
		SystemInfoModule(std::string const name);
		virtual ~SystemInfoModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif
