#include "Fleet.h"


void Fleet::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.05f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.1f, xFinal + 0.1f, yFinal + 0.05f, 0.25f, 0.25f, 0.29f);
}

float Fleet::getX(){
	return x;
}

float Fleet::getY(){
	return y;
}

Fleet::~Fleet()
{
}
