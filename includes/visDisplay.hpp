


#ifndef VISDISPLAY_HPP
# define VISDISPLAY_HPP
#include <SFML/Graphics.hpp>
#include "../includes/mainHeader.hpp"

class visDisplay : public IMonitorDisplay
{
	public:

		visDisplay(void);
		visDisplay(visDisplay const &obj);
		visDisplay	&operator=(visDisplay const &r);
		visDisplay(std::vector<IMonitorModule*> const mods);
		void displayButtons(std::vector<std::string> args);
		void displayTitle();
		void displayInfo(std::vector<std::string> args);
		void checkIfButtonPressed(std::vector<std::string> args, int x, int y);
		virtual ~visDisplay(void);

		
		void		updateScreen(std::vector<std::string> );
		void		updateData(std::vector<std::string> );
		
	private:
		std::vector<IMonitorModule*>	_mods;
		std::map <std::string, std::string> map;
		std::string current;
		sf::RenderWindow window;
		sf::Font font;
};

#endif