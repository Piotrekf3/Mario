#pragma once
#include "entity.h"
class Ground :
	public Entity
{
public:
	sf::Vector2f get_position();
	Ground(const string & texture_dir);
	virtual ~Ground();
};

