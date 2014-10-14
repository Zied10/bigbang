#include "Fire.h"

float Fire::getX(){
	return x;
}

float Fire::getY(){
	return y;
}

bool Fire::touchAsteroid(Asteroid& asteroid){
	if ((x + size) >= asteroid.getX() && (x + size) < (asteroid.getX() + 0.1f) && y >= asteroid.getY() - 0.001 && y <= asteroid.getY() + 0.18f){
		asteroid.removeVita(power);
		return true;
	}
	return false;
}

Fire::~Fire()
{
}
