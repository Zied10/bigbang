#pragma once
#include "Fire.h"
class Plasma :
	public Fire
{
public:
	Plasma(float x, float y) :Fire(x, y){
		power = 40;
		size = 0.01f;
	}
	void tick();
	void draw();

	~Plasma();
};

