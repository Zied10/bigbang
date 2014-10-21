#include "LittleAsteroid.h"


void LittleAsteroid::tick(){
	x -= 0.0002f;
}

void LittleAsteroid::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.05f, y + 0.05f, 0.1f, 0.1f, 0.0f, 0.0f, 1.0f);
}

LittleAsteroid::~LittleAsteroid()
{
}
