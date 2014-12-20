#pragma once
#include "Fleet.h"
class Destroyer :
	public Fleet
{
public:
	Destroyer(float x, float y) :Fleet(x, y){
		id = 3;
		currentVita = 250;
		maxVita = 250;
		price = 50;
	}

	void draw();
	void drawDescription();
	
};

