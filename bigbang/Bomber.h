#pragma once
#include "Fleet.h"
class Bomber :
	public Fleet
{
public:
	Bomber(float x, float y) :Fleet(x, y){
		id = 2;
		vita = 150;
		price = 30;
	}

	void draw();
	void drawVita();
	~Bomber();
};

