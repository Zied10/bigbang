#pragma once
#include "Asteroid.h"
class MiddleAsteroid :
	public Asteroid
{
public:
	MiddleAsteroid(float y) :Asteroid(y){
		vita = 250;
		power = 100;
	}
	void tick();
	void draw();

	~MiddleAsteroid();
};

