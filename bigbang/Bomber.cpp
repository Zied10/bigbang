#include "Bomber.h"


void Bomber::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.07f;
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal - 0.05, xFinal, yFinal + 0.1f, xFinal + 0.06f, yFinal + 0.025, 0.4f, 0.f, 0.f);
	GraphicPrimitives::drawFillTriangle2D(xFinal, yFinal, xFinal, yFinal + 0.05f, xFinal + 0.1f, yFinal + 0.025f, 0.25f, 0.35f, 0.3f);
}

void Bomber::drawDescription(){
	GraphicPrimitives::drawText2D("Faible CDT, bouclier moyen et puissance forte", -0.7, -0.9, 1., 1., 1.);
}

