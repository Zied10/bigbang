#pragma once
#include "Fire.h"
class Plasma :
	public Fire
{
public:
	Plasma(float x, float y) :Fire(x, y){
		power = 75;
		size = 0.005f;
	}
	void tick();
	void draw();

	
};

