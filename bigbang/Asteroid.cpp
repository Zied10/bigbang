#include "Asteroid.h"

void Asteroid::draw(){
	GraphicPrimitives::drawFillRect2D(x + 0.05f, y + 0.05f, 0.1f, 0.1f, 0.0f, 0.0f, 1.0f);
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
	if (vita < 0){
		return true;
	}
	return false;
}

void Asteroid::removeVita(int x){
	vita -= x;
}

bool Asteroid::touchFleet(Fleet& fleet){
	if (x  <= (fleet.getX() + 0.09) && x >= fleet.getX() && y >= fleet.getY() - 0.001 && y <= fleet.getY() + 0.18f){
		fleet.removeVitaFleet(power);
		return true;
	}
	return false;
}

Asteroid::~Asteroid()
{
}
