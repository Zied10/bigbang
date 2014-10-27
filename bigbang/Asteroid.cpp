#include "Asteroid.h"

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
	if (x  <= (fleet.getX() + 0.09) && x >= fleet.getX() && y >= fleet.getY() - 0.001 && y <= fleet.getY() + 0.18f){
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
void Asteroid::resetNumberAste(){
	numberAste = 0;
}

Asteroid::~Asteroid()
{
}
