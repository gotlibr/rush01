#include "../includes/mainHeader.hpp"

visDisplay::visDisplay(std::vector<IMonitorModule*> const mods):window(sf::VideoMode(1235, 800 , 32), "SFML works!")
{
  	// this->window = (sf::VideoMode(400, 400 , 32), "SFML works!");
    if (!this->font.loadFromFile("arial.ttf"))
    {
        std::cout << "No such font" << std::endl;
        exit (1);
    }
    
    this->_mods = mods;
    this->map["-p"]  = "img/cpu.png";
	this->map["-h"]  = "img/os.png";
	this->map["-n"]  = "img/host.png";
	this->map["-t"]  = "img/time.png";
	this->map["-m"]  = "img/memory.png";
	this->map["-i"]  = "img/network.png";
}

visDisplay::~visDisplay(void)
{

}

void visDisplay::displayButtons(std::vector<std::string> args)
{
	int x = 0;

    sf::Texture texture;
	for (int i = 0; i < args.size(); i++)
	{
		int k = 0;
		if (k != 6)
    	texture.loadFromFile((this->map.find(args[i]))->second, sf::IntRect(0, 0, 210, 110));
    	sf::Sprite sprite;
    	sprite.setTexture(texture);
    	sprite.setPosition(x,0);
		window.draw(sprite);
		x += 204;	
	}
}

void visDisplay::displayTitle()
{
	sf::Text titleText;

    titleText.setFont(this->font);
    titleText.setCharacterSize(70);
    titleText.setFillColor(sf::Color::Black);

    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	std::map <std::string, std::string> mapping;
	mapping["-p"]  = "CPU info";
	mapping["-h"]  = "OS info";
	mapping["-n"]  = "Host info";
	mapping["-t"]  = "System time";
	mapping["-m"]  = "Memory info";
	mapping["-i"]  = "Network info";
	titleText.setString(mapping.find(this->current)->second);
	titleText.setPosition(1235 / 2 - (mapping.find(this->current)->second.length() * 20), 150);
	this->window.draw(titleText);
}
void visDisplay::displayInfo(std::vector<std::string> args)
{
	int i = 0;
	int k = 0;
	int y = 350;
	sf::Text text;

	text.setFont(this->font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Black);
	while (i < args.size() && args[i] != this->current)
		i++;
	// std::cout<< this->_mods.at(i)->getResult().size()<< std::endl;
	if (i != args.size())
	{
		while (k < this->_mods.at(i)->getResult().size())
		{
			text.setString(text.getString() +"\n" + this->_mods.at(i)->getResult().at(k));
			k++;
		}
		text.setPosition(0,y);
		this->window.draw(text);
		y += 50;
	}
}

void visDisplay::checkIfButtonPressed(std::vector<std::string> args, int x, int y)
{
	std::map <int, std::string> mapping;
	mapping[0]  = "-h";
	mapping[1]  = "-p";
	mapping[2]  = "-n";
	mapping[3]  = "-t";
	mapping[4]  = "-m";
	mapping[5]  = "-i";
	std::cout <<x << std::endl;
	if (y <= 110)
		this->current = mapping[x / 210];
}

void visDisplay::updateScreen(std::vector<std::string> args)
{

  
    
  
    this->current = args[0];
    std::cout << this->_mods.size() << std::endl;
    sf::Clock clock;
    while (this->window.isOpen())
    {	
    	
        sf::Event event;
		sf::Time elapsed1;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        			checkIfButtonPressed(args, event.mouseButton.x , event.mouseButton.y );
        }
        elapsed1 = clock.getElapsedTime();
        if (elapsed1.asSeconds() >= 1)
        {
        	updateData(args);
        	clock.restart();
        }
        this->window.clear(sf::Color(69, 103, 130, 1));
        displayButtons(args);
        displayTitle();
        displayInfo(args);
        this->window.display();
    }

}

void					visDisplay::updateData(std::vector<std::string>  args)
{
	size_t i = 0;
	while (i < (this->_mods.size()))
	{
		this->_mods.at(i)->update();
		i++;
	}
	
	// updateScreen(args);
	return ;
}