#include "Vaisseau.h"


void Vaisseau::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.05f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.1f, xFinal + 0.1f, yFinal + 0.05f, 0.25f, 0.25f, 0.29f);
}

float Vaisseau::getX(){
	return x;
}

float Vaisseau::getY(){
	return y;
}

Vaisseau::~Vaisseau()
{
}
