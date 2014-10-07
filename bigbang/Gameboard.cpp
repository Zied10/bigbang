#include "Gameboard.h"
#include "Utility.h"


Gameboard::Gameboard(float posX_, float posY_, float width_, float color_) :
posX(posX_), 
posY(posY_), 
width(width_), 
color(color_), 
nbClick(0)
{
}

void Gameboard::draw(){
	char* afficheClick = new char[100];
	Utility::itoa(nbClick, afficheClick);
	GraphicPrimitives::drawFillRect2D(posX, posY, width, width, color, color, color);
	GraphicPrimitives::drawText2D(afficheClick, posX, posY, 0.0f, 0.0f, 0.0f);
}

float Gameboard::getPosX(){
	return posX;
}
float Gameboard::getPosY(){
	return posY;
}
float Gameboard::getWidth(){
	return width;
}
void Gameboard::setPosX(float newX){
	posX = newX;
}
void Gameboard::setPosY(float newY){
	posY = newY;
}

void Gameboard::addClick(){
	nbClick++;
}

int Gameboard::getNbClick(){
	return nbClick;
}
Gameboard::~Gameboard()
{
}
