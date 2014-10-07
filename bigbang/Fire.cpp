#include "Fire.h"


void Fire::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.14f, y + 0.09f, size + 0.02f, size, 1.0f, 0.0f, 0.0f);
}

float Fire::getX(){
	return x;
}

float Fire::getY(){
	return y;
}

Fire::~Fire()
{
}
