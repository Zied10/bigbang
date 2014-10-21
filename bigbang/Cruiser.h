#pragma once
#include "Fleet.h"
class Cruiser :
	public Fleet
{
public:
	Cruiser(float x, float y) :Fleet(x, y){
		id = 1;
		vita = 100;
		price = 10;
	}

	void draw();
	void drawVita();
	~Cruiser();
};

