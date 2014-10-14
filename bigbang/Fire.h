#pragma once
#include "GraphicPrimitives.h"
#include "Asteroid.h"
class Fire
{
protected:
	float x, y, size;
	int power;
public:
	Fire(float x_, float y_) :
		x(x_),
		y(y_){}
	virtual void draw() = 0;
	virtual void tick() = 0;
	bool touchAsteroid(Asteroid& asteroid);
	float getX();
	float getY();
	~Fire();
};

