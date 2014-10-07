#pragma once
#include "GraphicPrimitives.h"
class Vaisseau
{
protected:
	float x, y;
	float size;
	int vita;
public:
	Vaisseau(float x_, float y_, int vita_, float size_) :
		x(x_),
		y(y_),
		vita(vita_),
		size(size_){
	}
	virtual void draw();
	float getX();
	float getY();
	~Vaisseau();
};

