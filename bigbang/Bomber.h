#pragma once
#include "Fleet.h"
class Bomber :
	public Fleet
{
public:
	Bomber(int id, float x, float y) :Fleet(id, x, y){
		vita = 200;
	}

	void draw();
	void drawVita();
	~Bomber();
};

