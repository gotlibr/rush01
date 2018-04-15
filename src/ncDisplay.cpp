
#include "../includes/mainHeader.hpp"

ncDisplay::ncDisplay(std::vector<IMonitorModule*> const mods) : IMonitorDisplay(), _mods(mods)
																				
{

	initscr();
	timeout(0);
	cbreak();
	noecho();
	refresh();
	curs_set(false);

	keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    

    

	return ;
}

ncDisplay::~ncDisplay()
{
	endwin();
	return ;
}

static void printTitle(int num,std::vector<std::string> args, int y)
{
	int i = 0;

	attron(A_BOLD);
    std::string key[] = {"-h","-p","-n","-t","-m","-i"};
    std::string name[] = {"OS info", "CPU usage", "Host info", "Time info", "Memory usage", "Network activity"};
    while (key[i] != args[num] && i < 6)
    	i++;
    if (i != 6)
    {
    	
    	move(y,(70 - name[i].size()) / 2);
    	printw("%s", name[i].c_str());
    }
    attroff(A_BOLD);

}




void					ncDisplay::updateScreen(std::vector<std::string>  args)
{
	int i;
	int	j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 1;
	y = 1;
	erase();
	while (i < (this->_mods.size()))
	{
		//std::cout << this->_mods.size() << std::endl;
		j = 0;
		printTitle(i, args,  y);
		move(y ,70);
		whline(stdscr, ACS_VLINE, 1);
		y++;

		while (j < this->_mods.at(i)->getResult().size())
		{
			mvprintw(y, x, this->_mods.at(i)->getResult().at(j).c_str());
			move(y ,70);
			whline(stdscr, ACS_VLINE, 1);
			j++;
			y++;
		}
		move(y ,70);
		whline(stdscr, ACS_LRCORNER, 1);
		move(y ,0);
		whline(stdscr, ACS_HLINE, 70);
		y++;
		//mvprintw(1, 1, this->_mods.at(i)->getName().c_str());
		i++;
	}
	//mvprintw(y, x, this->_mods.at(1)->getResult().at(0).c_str());
	refresh();
	usleep(60000);
	



}

void					ncDisplay::updateData(std::vector<std::string>  args)
{
	size_t i = 0;
	while (i < (this->_mods.size()))
	{
		this->_mods.at(i)->update();
		i++;
	}
	updateScreen(args);
	return ;
}
