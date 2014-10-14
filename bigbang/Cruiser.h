#pragma once
#include "Fleet.h"
class Cruiser :
	public Fleet
{
public:
	Cruiser(int id, float x, float y) :Fleet(id, x, y){
		vita = 100;
	}

	void draw();
	void drawVita();
	~Cruiser();
};

