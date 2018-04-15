
#include "../includes/mainHeader.hpp"


RAMModule::RAMModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
}

RAMModule::~RAMModule()
{
	return ;
}

std::vector<std::string> const		&RAMModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&RAMModule::getName(void) const
{
	return (this->_name);
}

void								RAMModule::update(void)
{

	
		this->_result.clear();

	
	int				i = 0; 
	
	std::string		s1 = "used:";
	std::string		s2 = "wired:";
	std::string		s3 = "unused:";

	

	
	std::string s = "";
	std::system("top -l 1 -n 0 | grep PhysMem > ./sys_info/mem_info");
	std::ifstream				stream;
	stream.open("./sys_info/mem_info");
	while (getline(stream, s, ' '))
	{
		s.erase(std::remove(s.begin(), s.end(), ')'), s.end());
		s.erase(std::remove(s.begin(), s.end(), '('), s.end());

		if (isdigit(s.at(0)))



			{
				if (i == 0)
					this->_result.push_back(s1.append(s.append("M")));
				else if (i == 1)
					this->_result.push_back(s2.append(s.append("M")));
				else if (i == 2)
					this->_result.push_back(s3.append(s.append("M")));
				i++;
				


			}
	}
	

	stream.close();
	remove("./sys_info/mem_info");
	
	

	return ;

}