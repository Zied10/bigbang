#pragma once
#include "GraphicPrimitives.h"
#include "Utility.h"

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
	void removeClick();
	int getNbClick();
	static void rmClick(std::vector<std::vector<Gameboard *> > gm, float x, float y);
	
};

