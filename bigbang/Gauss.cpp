#include "Gauss.h"

void Gauss::tick(){
	x += 0.001f;
}

void Fire::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.14f, y + 0.09f, size + 0.02f, size, 1.0f, 0.2f, 0.0f);
}
