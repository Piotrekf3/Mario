#include "Ground.h"
#include"Variables.h"


Ground::Ground(const string & texture_dir) :
	Entity(texture_dir, sf::Vector2f(resoultion_x, resolution_y - resolution_y / ground_position_multiplier), sf::Vector2f(0, resolution_y / ground_position_multiplier))
{
	sprite.setScale(sf::Vector2f(5, 8));
}


Ground::~Ground()
{
}

sf::Vector2f Ground::get_position()
{
	return rect.getPosition();
}
