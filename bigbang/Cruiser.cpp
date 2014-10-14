#include "Cruiser.h"

void Cruiser::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.05f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.1f, xFinal + 0.1f, yFinal + 0.05f, 0.32f, 0.18f, 0.18f);
}

void Cruiser::drawVita(){
	GraphicPrimitives::drawLine2D(x + 0.045, y + 0.03, x + 0.135, y + 0.03, 1.f, 0.f, 0.f);
}


