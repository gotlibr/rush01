#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "../includes/mainHeader.hpp"


class RAMModule : public IMonitorModule
{
	public:
		RAMModule(void);
		RAMModule(RAMModule const &obj);
		RAMModule	&operator=(RAMModule const &r);
		RAMModule(std::string const name);
		virtual ~RAMModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif
