#pragma once
#include "Asteroid.h"
class LittleAsteroid :
	public Asteroid
{
private:
public:
	LittleAsteroid(float y) :Asteroid(y, vita){
		vita = 100;
	}
	void tick();
	~LittleAsteroid();
};

