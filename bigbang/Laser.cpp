#include "Laser.h"

void Laser::tick(){
	x += 0.005f;
}

void Laser::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.14f, y + 0.09f, size + 0.02f, size, 1.0f, 0.0f, 0.0f);
}