#include "Destroyer.h"


void Destroyer::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.07f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.05f, xFinal + 0.1f, yFinal + 0.1, 0.f, 1.f, 0.f);
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.05f, xFinal + 0.1f, yFinal + 0.025f, 0.f, 1.f, 0.f);
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.05f, xFinal + 0.1f, yFinal + 0.025f - 0.075, 0.f, 1.f, 0.f);
}
