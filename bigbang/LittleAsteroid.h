#pragma once
#include "Asteroid.h"
class LittleAsteroid :
	public Asteroid
{
private:
public:
	LittleAsteroid(float y) :Asteroid(y){
		vita = 150;
		power = 50;
		size = 0.01;
	}
	void tick();
	~LittleAsteroid();
};

