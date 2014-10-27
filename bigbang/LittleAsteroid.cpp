#include "LittleAsteroid.h"


void LittleAsteroid::tick(){
	x -= 0.0002f;
}

void LittleAsteroid::draw(){
	std::vector<float> vectX;
	std::vector<float> vectY;

	vectX.emplace_back(x + 0.07f);
	vectY.emplace_back(y + 0.09f);

	vectX.emplace_back(x + 0.07f + (0.1f / 2));
	vectY.emplace_back(y + 0.09f + (0.1f / 2));

	vectX.emplace_back(x + 0.06f + 0.1f);
	vectY.emplace_back(y + 0.09f);

	vectX.emplace_back(x + 0.08f + (0.1f / 2));
	vectY.emplace_back(y + 0.09f - (0.1f / 2));
	GraphicPrimitives::drawFillPolygone2D(vectX, vectY, 0.24f, 0.21, 0.21f);
	//GraphicPrimitives::drawFillRect2D(x + 0.05f, y + 0.05f, 0.1f, 0.1f, 0.0f, 0.0f, 1.0f);
}

LittleAsteroid::~LittleAsteroid()
{
}
