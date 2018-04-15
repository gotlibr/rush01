


#ifndef NCDISPLAY_HPP
# define NCDISPLAY_HPP

#include "../includes/mainHeader.hpp"

class ncDisplay : public IMonitorDisplay
{
	public:

		ncDisplay(void);
		ncDisplay(ncDisplay const &obj);
		ncDisplay	&operator=(ncDisplay const &r);
		ncDisplay(std::vector<IMonitorModule*> const mods);
		virtual ~ncDisplay(void);
		
		void		updateScreen(std::vector<std::string> );
		void		updateData(std::vector<std::string> );
		
	private:
		std::vector<IMonitorModule*>	_mods;

};

#endif