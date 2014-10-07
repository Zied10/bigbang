#include "Laser.h"

void Laser::tick(){
	x += 0.005f;
}

bool Laser::touchAsteroid(Asteroid& asteroid){
	//std::cout << "laser : " << y << std::endl;
	if ((x + size) >= asteroid.getX() && (x + size) < (asteroid.getX() + 0.1f) && y >= asteroid.getY() - 0.001 && y <= asteroid.getY() + 0.18f){
		asteroid.removeVita(power);
		return true;
		}
	return false;
}