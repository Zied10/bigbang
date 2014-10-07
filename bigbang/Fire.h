#pragma once
#include "GraphicPrimitives.h"
#include "LittleAsteroid.h"
class Fire
{
protected:
	float x, y, size;
	int power;
public:
	Fire(float x_, float y_, float size_) :
		x(x_),
		y(y_),
		size(size_){}
	void draw();
	virtual void tick() = 0;
	virtual bool touchAsteroid(Asteroid& asteroid) = 0;
	float getX();
	float getY();
	~Fire();
};

