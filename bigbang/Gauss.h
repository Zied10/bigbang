#pragma once
#include "Fire.h"
class Gauss :
	public Fire
{
public:
	Gauss(float x, float y) :Fire(x, y){
		power = 80;
		size = 0.015f;
	}
	void tick();
	void draw();
	
};

