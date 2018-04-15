
#include "../includes/mainHeader.hpp"


SystemInfoModule::SystemInfoModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
	struct utsname	utsname;
	uname(&utsname);
	std::string		os = "Os:";
	std::string		release = "Release:";

	this->_result.push_back(os.append(utsname.sysname));
	this->_result.push_back(release.append(utsname.release));
	return ;


}

SystemInfoModule::~SystemInfoModule()
{
	return ;
}

std::vector<std::string> const		&SystemInfoModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&SystemInfoModule::getName(void) const
{
	return (this->_name);
}

void								SystemInfoModule::update(void)
{


}