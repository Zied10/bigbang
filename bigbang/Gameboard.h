#pragma once
#include "GraphicPrimitives.h"
class Gameboard
{
private:
	float posX, posY, width, color;
	int nbClick;
public:
	Gameboard(float posX_, float posY_, float width_, float color_);
	void draw();
	float getPosX();
	float getPosY();
	float getWidth();
	void setPosX(float newX);
	void setPosY(float newY);
	void addClick();
	int getNbClick();
	~Gameboard();
};
