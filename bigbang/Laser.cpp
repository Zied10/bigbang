#include "Laser.h"

void Laser::tick(){
	x += 0.005f;
}

bool Laser::touchAsteroid(Asteroid& asteroid){
	if ((x + size) > asteroid.getX() && (x + size) < (asteroid.getX() + 0.1f) && y > asteroid.getY() && y < (asteroid.getY() + 0.1f)){
		std::cout <<  asteroid.getVita() << std::endl;
		asteroid.removeVita(power);
		return true;
		}
	return false;
}