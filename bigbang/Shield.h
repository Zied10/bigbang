#pragma once
#include "Fleet.h"
class Shield :
	public Fleet
{
public:
	Shield(float x, float y) :Fleet(x, y){
		id = 4;
		currentVita = 150;
		maxVita = 150;
		price = 10;
	}

	void draw();
	void drawVita();
	~Shield();
};

