#pragma once
#include "Asteroid.h"
class LittleAsteroid :
	public Asteroid
{
private:
public:
	LittleAsteroid(float y) :Asteroid(y){
		vita = 100;
		power = 50;
	}
	void tick();
	~LittleAsteroid();
};

