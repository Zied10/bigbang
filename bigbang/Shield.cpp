#include "Shield.h"


void Shield::draw(){
	float xFinal = x + 0.07f;
	float yFinal = y + 0.07f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal - 0.05, xFinal, yFinal + 0.1f, xFinal + 0.06f, yFinal + 0.025, 0.7f, 0.58f, 0.48f);
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.05f, xFinal + 0.07f, yFinal + 0.025f, 0.7f, 0.58f, 0.48f);
}
