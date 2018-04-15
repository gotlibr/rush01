
#include "../includes/mainHeader.hpp"


TimeModule::TimeModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
	

	return ;
}

TimeModule::~TimeModule()
{
	return ;
}

std::vector<std::string> const		&TimeModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&TimeModule::getName(void) const
{
	return (this->_name);
}

void								TimeModule::update(void)
{

	this->_result.clear();
   time_t now = time(0);
   char* dt = ctime(&now);
   std::string		local_time = "Local time: ";
   std::string		UTC_time = "UTC time: ";

   this->_result.push_back(local_time.append(dt));
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
    this->_result.push_back(UTC_time.append(dt));
	return ;

}