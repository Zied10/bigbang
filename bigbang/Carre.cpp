#include "Carre.h"
#include "Utility.h"


Carre::Carre(float posX_, float posY_, float width_, float color_) :
posX(posX_), 
posY(posY_), 
width(width_), 
color(color_), 
nbClick(0)
{
}

void Carre::draw(){
	char* afficheClick = new char[100];
	Utility::itoa(nbClick, afficheClick);
	GraphicPrimitives::drawFillRect2D(posX, posY, width, width, color, color, color);
	GraphicPrimitives::drawText2D(afficheClick, posX, posY, 0.0f, 0.0f, 0.0f);
}

float Carre::getPosX(){
	return posX;
}
float Carre::getPosY(){
	return posY;
}
float Carre::getWidth(){
	return width;
}
void Carre::setPosX(float newX){
	posX = newX;
}
void Carre::setPosY(float newY){
	posY = newY;
}

void Carre::addClick(){
	nbClick++;
}

int Carre::getNbClick(){
	return nbClick;
}
Carre::~Carre()
{
}
