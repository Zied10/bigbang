#include "Plasma.h"


void Plasma::tick(){
	x += 0.009f;
}

void Plasma::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.14f, y, size, 0.183, 0.0f, 0.4f, 0.0f);
}

