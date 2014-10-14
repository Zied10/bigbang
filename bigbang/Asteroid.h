#pragma once
#include "GraphicPrimitives.h"
#include "Fleet.h"
class Asteroid
{
protected:
	float x, y;
	int vita, power;
public:
	Asteroid(float y_) :
		x(1.01f),
		y(y_){
	}
	float getX();
	float getY();
	int getVita();
	void removeVita(int power);
	bool isDied();
	virtual void tick() = 0;
	virtual void draw() = 0;
	bool touchFleet(Fleet& fleet);
	~Asteroid();
};

