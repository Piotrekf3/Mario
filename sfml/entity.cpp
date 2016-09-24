#include "entity.h"
#include<iostream>
using std::cout;

Entity::Entity()
{

}

Entity::Entity(const string & texture_dir,const sf::Vector2f & rect_size,const sf::Vector2f & position)
{
	//loading texture
	if (!texture.loadFromFile(texture_dir))
		cout << "b³¹d wczytywania tekstury\n";
	//creating rect
	rect.setSize(rect_size);
	rect.setPosition(position);
	//creating sprite
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, rect.getSize().x, rect.getSize().y));
	update_sprite();

}

void Entity::draw(sf::RenderWindow & window) const
{
	window.draw(sprite);
}

void Entity::update_sprite()
{
	sprite.setPosition(rect.getPosition());
}