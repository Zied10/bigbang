#include "Plasma.h"


void Plasma::tick(){
}

void Plasma::draw(){
	GraphicPrimitives::drawLine2D(x + 0.14f, y + 0.09f, 1., y + 0.09f, 0.0f, 0.5f, 0.0f);
}

