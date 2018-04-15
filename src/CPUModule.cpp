
#include "../includes/mainHeader.hpp"


CPUModule::CPUModule(std::string const name) : IMonitorModule(), _result(), _name(name)
{
	char 			array[100];
	size_t 			arraylen = 100;
	sysctlbyname("machdep.cpu.brand_string", &array, &arraylen, NULL, 0);
	std::string str(array);
	this->_result.push_back(str);
	update();

	return ;
}

CPUModule::~CPUModule()
{
	return ;
}

std::vector<std::string> const		&CPUModule::getResult(void) const
{
	return (this->_result);
}

				

std::string const					&CPUModule::getName(void) const
{
	return (this->_name);
}

void								CPUModule::update(void)
{

	if (this->_result.size() > 0)
		this->_result.erase(this->_result.begin() + 1 , this->_result.end());

	
	int				i = 0; 
	
	std::string		s1 = "user:";
	std::string		s2 = "sys:";
	std::string		s3 = "idle:";

	

	
	std::string s = "";
	std::system("top -l 1 -n 0 | grep CPU > ./sys_info/cpu_info");
	std::ifstream				stream;
	stream.open("./sys_info/cpu_info");
	while (getline(stream, s, ' '))
	{
		if (isdigit(s.at(0)))
			{
				if (i == 0)
					this->_result.push_back(s1.append(s.append("%")));
				else if (i == 1)
					this->_result.push_back(s2.append(s.append("%")));
				else if (i == 2)
					this->_result.push_back(s3.append(s.append("%")));
				i++;
			}
	}
	

	stream.close();
	remove("./sys_info/cpu_info");
	
	

	return ;

}