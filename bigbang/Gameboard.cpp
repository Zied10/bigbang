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

void Gameboard::removeClick(){
	nbClick--;
}

void Gameboard::rmClick(std::vector<std::vector<Gameboard *> > gm, float x, float y){
	bool stop = false;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (gm[i][j]->getPosX() == x && gm[i][j]->getPosY() == y){
				gm[i][j]->removeClick();
				stop = true;
				break;
			}
		}
		if (stop){
			break;
		}
	}
}

int Gameboard::getNbClick(){
	return nbClick;
}
Gameboard::~Gameboard()
{
}
