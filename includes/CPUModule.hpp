




#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "../includes/mainHeader.hpp"


class CPUModule : public IMonitorModule
{
	public:
		CPUModule(void);
		CPUModule(CPUModule const &obj);
		CPUModule	&operator=(CPUModule const &r);
		CPUModule(std::string const name);
		virtual ~CPUModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif
