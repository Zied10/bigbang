#pragma once
#include "Asteroid.h"
class MiddleAsteroid :
	public Asteroid
{
public:
	MiddleAsteroid(float y) :Asteroid(y){
		vita = 250;
		power = 100;
		size = 0.025;
	}
	void tick();

	~MiddleAsteroid();
};

