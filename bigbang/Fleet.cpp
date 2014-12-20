#include "Fleet.h"


void Fleet::drawVita(){
	float rapport = ((float)currentVita / (float)maxVita);
	GraphicPrimitives::drawLine2D(x + 0.045, y + 0.01, x + 0.135, y + 0.01, 1.f, 0.f, 0.f);
	GraphicPrimitives::drawLine2D(x + 0.045, y + 0.01, x + 0.045 + 0.09 * rapport, y + 0.01, 0.f, 1.f, 0.f);
}

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

int Fleet::getTickFleet(){
	return tickFleet;
}

void Fleet::incrTickFleet(){
	tickFleet += 1;
}

void Fleet::drawPrice(){
	char* charPrice = new char[100];
	Utility::itoa(price, charPrice);
	GraphicPrimitives::drawText2D(charPrice, x, y, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("$", x + 0.07, y, 1.0f, 1.0f, 0.0f);
	delete[] charPrice;
}

void Fleet::drawSelect(){
	GraphicPrimitives::drawFillRect2D(x + 0.01, y - 0.01, 0.15, 0.18, .2, .2, .2);
}