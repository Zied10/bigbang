#include "MiddleAsteroid.h"

void MiddleAsteroid::tick(){
	x -= 0.0001f;
}

void MiddleAsteroid::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.05f, y + 0.05f, 0.1f, 0.1f, 0.0f, 0.0f, 1.0f);
}

MiddleAsteroid::~MiddleAsteroid()
{
}
