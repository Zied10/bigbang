#pragma once
#include "Fire.h"
class Gauss :
	public Fire
{
public:
	Gauss(float x, float y) :Fire(x, y){
		power = 50;
		size = 0.15f;
	}
	void tick();
	void draw();
	~Gauss();
};

