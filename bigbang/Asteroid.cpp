#include "Asteroid.h"

void Asteroid::draw(){
	std::vector<float> vectX;
	std::vector<float> vectY;

	vectX.emplace_back(x);
	vectY.emplace_back(y + 0.09f);

	vectX.emplace_back(x+ 0.01f + size);
	vectY.emplace_back(y + 0.09f + 0.04f + size/2);

	vectX.emplace_back(x+ 0.06f + size);
	vectY.emplace_back(y + 0.09f + 0.04f + size/2);

	vectX.emplace_back(x + 0.06f + 2*size+ 0.01f);
	vectY.emplace_back(y + 0.09f);

	vectX.emplace_back(x+ 0.06f + size);
	vectY.emplace_back(y + 0.09f - 0.04f - size/2);

	vectX.emplace_back(x + 0.01f + size);
	vectY.emplace_back(y + 0.09f - 0.04f - size/2);

	GraphicPrimitives::drawFillPolygone2D(vectX, vectY, 0.24f, 0.21, 0.21f);
}

float Asteroid::getX(){
	return x;
}

float Asteroid::getY(){
	return y;
}

int Asteroid::getVita(){
	return vita;
}

bool Asteroid::isDied(){
	if (vita <= 0){
		return true;
	}
	return false;
}

void Asteroid::removeVita(int x){
	vita -= x;
}

bool Asteroid::touchFleet(Fleet& fleet){
	if (x  <= (fleet.getX() + 0.14) && x >= fleet.getX() && y >= fleet.getY() - 0.001 && y <= fleet.getY() + 0.18f){
		fleet.removeVitaFleet(power);
		return true;
	}
	return false;
}

int Asteroid::numberAste = 0;

void Asteroid::addNumberAste(){
	numberAste += 1;
}

int Asteroid::getNumberAste(){
	return numberAste;
}

int Asteroid::getPower(){
	return power;
}

void Asteroid::resetNumberAste(){
	numberAste = 0;
}

