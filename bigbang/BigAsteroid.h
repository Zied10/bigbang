#pragma once
#include "Asteroid.h"
class BigAsteroid :
	public Asteroid
{
public:
	BigAsteroid(float y) :Asteroid(y){
		vita = 500;
		power = 200;
		size = 0.04;
	}
	void tick();
	~BigAsteroid();
};

