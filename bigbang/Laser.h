#pragma once
#include "Fire.h"
class Laser :
	public Fire
{
public:
	Laser(float x, float y) :Fire(x, y){
		power = 40;
		size = 0.01f;
	}
	void tick();
	void draw();
	
};

