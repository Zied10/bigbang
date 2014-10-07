#pragma once
#include "GraphicPrimitives.h"
class Asteroid
{
protected:
	float x, y;
	int vita;
public:
	Asteroid(float y_, int vita_) :
		x(1.01f),
		y(y_),
		vita(vita_){}
	void draw();
	float getX();
	float getY();
	int getVita();
	void removeVita(int x);
	bool isDied();
	virtual void tick() = 0;
	~Asteroid();
};

