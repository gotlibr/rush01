

#include "../includes/mainHeader.hpp"

HostUserModule::HostUserModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
	char host[255]; 
	char username[255];
	std::string		s1 = "Hostname:";
	std::string		s2 = "Username:";
	gethostname(host, 255);
	getlogin_r(username, 255);

	this->_result.push_back(s1.append(host));
	this->_result.push_back(s2.append(username));

	return ;


}

HostUserModule::~HostUserModule()
{
	return ;
}

std::vector<std::string> const		&HostUserModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&HostUserModule::getName(void) const
{
	return (this->_name);
}

void								HostUserModule::update(void)
{


}