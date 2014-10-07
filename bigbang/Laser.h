#pragma once
#include "Fire.h"
#include "LittleAsteroid.h"
class Laser :
	public Fire
{
public:
	Laser(float x, float y, float size) :Fire(x, y, size){
		power = 50;
	}
	void tick();
	bool touchAsteroid(Asteroid& asteroid);
	~Laser();
};

