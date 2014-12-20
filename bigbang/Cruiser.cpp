#include "Cruiser.h"

void Cruiser::draw(){
	float xFinal = x + 0.05f;
	float yFinal = y + 0.095f;

	std::vector<float> vectX;
	std::vector<float> vectY;

	vectX.emplace_back(xFinal);
	vectY.emplace_back(yFinal);

	vectX.emplace_back(xFinal);
	vectY.emplace_back(yFinal + 0.02f);

	vectX.emplace_back(xFinal + 0.01f);
	vectY.emplace_back(yFinal + 0.02f + 0.04f);

	vectX.emplace_back(xFinal + 0.02f);
	vectY.emplace_back(yFinal + 0.02f);

	vectX.emplace_back(xFinal + 0.09f);
	vectY.emplace_back(yFinal);

	vectX.emplace_back(xFinal + 0.02f);
	vectY.emplace_back(yFinal - 0.02f);

	vectX.emplace_back(xFinal + 0.01f);
	vectY.emplace_back(yFinal - 0.02f - 0.04f);

	vectX.emplace_back(xFinal);
	vectY.emplace_back(yFinal - 0.02f);
	

	GraphicPrimitives::drawFillPolygone2D(vectX, vectY, 0.f, 0.f, 1.f);
}

void Cruiser::drawDescription(){
	GraphicPrimitives::drawText2D("Forte CDT, bouclier et puissance faible", -0.7, -0.9, 1., 1., 1.);
}

