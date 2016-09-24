#include <SFML/Graphics.hpp>
#include"entity.h"
#include"Player.h"
#include"Ground.h"
#include"Variables.h"
#include<iostream>
#include"Resource_path.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(resoultion_x, resolution_y), "Mario!");
	window.setFramerateLimit(FPS);

	//creating ground object
	Ground *ground=new Ground(sprites_dir + "/ground.png" );
	//creating player object
	Player *player=new Player(sprites_dir + "/player.png");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//zamykanie esc
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();


		window.clear(sf::Color::Cyan);

		ground->draw(window);
		player->draw(window);
		player->update_move(ground->get_position().y);

		window.display();
	}

	delete player;
	delete ground;
	return 0;
}