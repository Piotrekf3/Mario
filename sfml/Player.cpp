#include "Player.h"
#include"Variables.h"
#include<iostream>
using std::cout;

const double Player::scale = 3;
const int Player::sprite_size_x=16;
const int Player::sprite_size_y = 20;
Player::Player(const string & texture_dir) : 
	Entity(texture_dir, sf::Vector2f(sprite_size_x*scale, sprite_size_y*scale), sf::Vector2f(0, (resolution_y / ground_position_multiplier)-scale*sprite_size_y))
{
	sprite.setScale(sf::Vector2f(scale,scale));
}

void Player::update_move(const double & ground_position_y)
{
	static int steps_counter = 0;
	static bool is_jumping = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) && rect.getPosition().y == ground_position_y - (scale*sprite_size_y))
	{
		is_jumping = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		directory = true;
		rect.move(2 * speed, 0);
		sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, 0, sprite_size_x, sprite_size_y));
		steps_counter++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		directory = true;
		rect.move(speed, 0);
		sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, 0, sprite_size_x, sprite_size_y));
		steps_counter++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		directory = false;
		rect.move(-2 * speed, 0);
		sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, sprite_size_y, sprite_size_x, sprite_size_y));
		steps_counter++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		directory = false;
		rect.move(-speed, 0);
		sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, sprite_size_y, sprite_size_x, sprite_size_y));
		steps_counter++;
	}
	
	else
	{
		steps_counter = 0;
		if (directory)
			sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, 0, sprite_size_x, sprite_size_y));
		else
			sprite.setTextureRect(sf::IntRect(steps_counter * sprite_size_x, sprite_size_y, sprite_size_x, sprite_size_y));
	}
	if (is_jumping)
	{
		if (rect.getPosition().y < ground_position_y - (scale*sprite_size_y) - jump_height)
		{
			is_jumping = false;
		}
		else
		{
		rect.move(0, -3 * speed);
		if (directory)
			sprite.setTextureRect(sf::IntRect(4 * sprite_size_x, 0, sprite_size_x, sprite_size_y));
		else
			sprite.setTextureRect(sf::IntRect(4 * sprite_size_x, sprite_size_y, sprite_size_x, sprite_size_y));
		}
	}
	else if (rect.getPosition().y < ground_position_y - (scale*sprite_size_y))
	{
		cout << rect.getPosition().y << std::endl;
		rect.move(0, 3 * speed);
		if (directory)
			sprite.setTextureRect(sf::IntRect(4 * sprite_size_x, 0, sprite_size_x, sprite_size_y));
		else
			sprite.setTextureRect(sf::IntRect(4 * sprite_size_x, sprite_size_y, sprite_size_x, sprite_size_y));
	}
	update_sprite();
	if (steps_counter >= 4)
		steps_counter = 0;
}
