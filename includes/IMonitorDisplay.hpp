
#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "../includes/mainHeader.hpp"

class IMonitorDisplay
{
	public:

		IMonitorDisplay(void);
		IMonitorDisplay(IMonitorDisplay const &obj);
		virtual ~IMonitorDisplay(void);

		virtual void		updateScreen(std::vector<std::string> ) = 0;
		virtual void		updateData(std::vector<std::string> ) = 0;
		
		IMonitorDisplay	&operator=(IMonitorDisplay const &r);
};

#endif