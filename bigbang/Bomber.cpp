#include "Bomber.h"


void Bomber::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.05f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.1f, xFinal + 0.1f, yFinal + 0.05f, 0.25f, 0.65f, 0.3f);
	GraphicPrimitives::drawFillTriangle2D(xFinal + 0.01f, yFinal + 0.01f, xFinal + 0.01f, yFinal + 0.09f, xFinal + 0.09f, yFinal + 0.05f, 0.4f, 0.f, 0.f);
	GraphicPrimitives::drawFillTriangle2D(xFinal + 0.02f, yFinal + 0.02f, xFinal + 0.02f, yFinal + 0.08f, xFinal + 0.08f, yFinal + 0.05f, 0.f, 0.f, 0.3f);
}

void Bomber::drawVita(){
	GraphicPrimitives::drawLine2D(x + 0.045, y + 0.03, x + 0.135, y + 0.03, 1.f, 0.f, 0.f);
}

Bomber::~Bomber()
{
}
