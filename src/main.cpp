
#include "../includes/mainHeader.hpp"

bool				checkArgs(char const *args[], int ac)
{
	int				i;
	int				j;

	int				error;
	const char 		*flags[] = {"-p", "-h", "-n", "-t", "-m", "-i"};

	i = 1;
	j = -1;
	error = 0;
	if (ac < 2)
		return (false);
	if (strcmp(args[1], "-v") && strcmp(args[1], "-t"))
		return (false);
	while (++i < ac)
	{
		while(++j < 6)
		{
			if (strcmp(args[i], flags[j]) == 0)
				error = 1;
		}
		if (error == 0)
			return(false);
		error = 0;
		j = -1;
	}
	return(true);
}

void	nc_display(std::vector<std::string> arguments, int mode)
{
	std::vector<IMonitorModule*> 		mods;
	std::vector<std::string>::iterator it;
	//int 			n;

	std::map <std::string, int> mapping;
	mapping["-p"]  = 1;
	mapping["-h"]  = 2;
	mapping["-n"]  = 3;
	mapping["-t"]  = 4;
	mapping["-m"]  = 5;
	mapping["-i"]  = 6;


	//n = 1;
	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		//std::cout << n << std::endl;
		switch (mapping[*it]) {
    	case 1:  mods.push_back(new CPUModule("CPU"));;
    	break;
    	case 2:  mods.push_back(new SystemInfoModule("Os Info"));;
    	break;
    	case 3:  mods.push_back(new HostUserModule("Host/User"));;
    	break;
    	case 4:  mods.push_back(new TimeModule("Time"));;
    	break;
    	case 5:  mods.push_back(new RAMModule("RAM"));;
    	break;
    	case 6:  mods.push_back(new NetworkModule("Network"));;
    	case 7: ;
		}

  	
	}

	

	//display.updateScreen();
	if (mode == 0)
	{
		ncDisplay		display(mods);
		while (1)
		{
		
			if ((getch()) != ERR)
			{
				endwin();
				exit(1);
			}
			display.updateData(arguments);	
		}
	}
	else
	{
		visDisplay		display(mods);
		display.updateScreen(arguments);
	}

	
}

void	visual_display(std::vector<std::string> arguments)
{
	std::vector<IMonitorModule*> 		mods;
	std::vector<std::string>::iterator it;
	//int 			n;

	std::map <std::string, int> mapping;
	mapping["-p"]  = 1;
	mapping["-h"]  = 2;
	mapping["-n"]  = 3;
	mapping["-t"]  = 4;
	mapping["-m"]  = 5;
	mapping["-i"]  = 6;


	//n = 1;
	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		//std::cout << n << std::endl;
		switch (mapping[*it]) {
    	case 1:  mods.push_back(new CPUModule("CPU"));;
    	break;
    	case 2:  mods.push_back(new SystemInfoModule("Os Info"));;
    	break;
    	case 3:  mods.push_back(new HostUserModule("Host/User"));;
    	break;
    	case 4:  mods.push_back(new TimeModule("Time"));;
    	break;
    	case 5:  mods.push_back(new RAMModule("RAM"));;
    	break;
    	case 6:  mods.push_back(new NetworkModule("Network"));;
    	case 7: ;
		}
	}
	visDisplay		display(mods);
	display.updateData(arguments);
	display.updateScreen(arguments);
	// //display.updateScreen();
	// while (1)
	// {
		
	// 		if ((getch()) != ERR)
	// 		{
	// 			endwin();
	// 			exit(1);
	// 		}
	// 		display.updateData(arguments);	
	// }

	
}
		


int		 main(int argc, char const *argv[])
{
	std::vector<std::string> arguments;
	std::vector<std::string>::iterator it;
	std::cout<<"\033[8;28;71t";
	system("export LD_LIBRARY_PATH=/Users/hlriabts/homebrew/Cellar/sfml/2.4.2_1/lib");
	if (!checkArgs(argv,argc))
	{
		std::cout <<  "fail" << std::endl;
		return (-1);
	}
	arguments.assign(argv, argv + argc);
	arguments.erase(arguments.begin());
	arguments.erase(arguments.begin());
	//std::sort(arguments.begin(), arguments.end());
  	arguments.erase(unique(arguments.begin(), arguments.end()), arguments.end());

	for (it = arguments.begin(); it != arguments.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	if (strcmp(argv[1], "-t") == 0)
		nc_display(arguments, 0);
	else if (strcmp(argv[1], "-v") == 0)
		nc_display(arguments, 1);

	

	return 0;
}