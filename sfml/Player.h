#pragma once
#include "entity.h"
class Player :
	public Entity
{
private:

	//zmienne
	double speed = 10;
	int jump_height = 200;
	bool directory = true;
	//zmienne statyczne
	const static int sprite_size_x;
	const static int sprite_size_y;
	const static double scale;
public:
	virtual void update_move(const double & ground_position_y);
	Player();
	Player(const string & texture_dir);
	virtual ~Player(){};
};

