#include "Fleet.h"


float Fleet::getX(){
	return x;
}

float Fleet::getY(){
	return y;
}

bool Fleet::isDied(){
	if (vita <= 0){
		return true;
	}
	return false;
}

void Fleet::removeVitaFleet(int power){
	vita -= power;
}

void Fleet::setVita(int newVita){
	vita = newVita;
}

int Fleet::getId(){
	return id;
}

Fleet::~Fleet()
{
}
