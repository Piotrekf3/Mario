#pragma once
#include<SFML\Graphics.hpp>
#include<string>
using std::string;
class Entity
{
protected:
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Sprite sprite;
	//update sprite position to rect position
	void update_sprite();
public:
	//draws object
	virtual void draw(sf::RenderWindow & window) const;
	Entity();
	Entity(const string & texture_dir,const sf::Vector2f & rect_size, const sf::Vector2f & position);
	virtual ~Entity(){};

};

