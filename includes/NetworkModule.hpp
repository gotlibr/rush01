#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#include "../includes/mainHeader.hpp"


class NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(void);
		NetworkModule(NetworkModule const &obj);
		NetworkModule	&operator=(NetworkModule const &r);
		NetworkModule(std::string const name);
		virtual ~NetworkModule(void);
		
		void							update(void);
		std::vector<std::string> const	&getResult(void) const;
		std::string const				&getName(void) const;
		
	private:
		std::vector<std::string>		_result;
		std::string						_name;
	
};

#endif