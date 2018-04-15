
#include "../includes/mainHeader.hpp"


NetworkModule::NetworkModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
	
}

NetworkModule::~NetworkModule()
{
	return ;
}

std::vector<std::string> const		&NetworkModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&NetworkModule::getName(void) const
{
	return (this->_name);
}

void								NetworkModule::update(void)
{

	
		this->_result.clear();

	
	int				i = 0; 
	
	std::string		s1 = "Packets in:";
	std::string		s2 = "Packets out:";


	

	
	std::string s = "";
	std::system("top -l 1 -n 0 | grep Networks > ./sys_info/net_info");
	std::ifstream				stream;
	stream.open("./sys_info/net_info");
	while (getline(stream, s, ' '))
	{
		

		if (isdigit(s.at(0)))



			{
				if (i == 0)
					this->_result.push_back(s1.append(s));
				else if (i == 1)
					this->_result.push_back(s2.append(s));
				i++;
				


			}
	}
	

	stream.close();
	remove("./sys_info/mem_info");
	
	

	return ;

}