#pragma once
#include "Fleet.h"
class Cruiser :
	public Fleet
{
public:
	Cruiser(float x, float y, int vita, float size) :Fleet(x, y, vita, size){
	}
	~Cruiser();
};

