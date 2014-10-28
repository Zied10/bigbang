#include "Fleet.h"


float Fleet::getX(){
	return x;
}

float Fleet::getY(){
	return y;
}

bool Fleet::isDied(){
	if (currentVita <= 0){
		return true;
	}
	return false;
}

void Fleet::removeVitaFleet(int power){
	currentVita -= power;
}

void Fleet::setCurrentVita(int newVita){
	currentVita = newVita;
}

int Fleet::getCurrentVita(){
	return currentVita;
}

int Fleet::getMaxVita(){
	return maxVita;
}

int Fleet::getId(){
	return id;
}

int Fleet::getPrice(){
	return price;
}

Fleet::~Fleet()
{
}
