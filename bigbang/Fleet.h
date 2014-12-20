#pragma once
#include "GraphicPrimitives.h"
#include "Gameboard.h"
class Fleet
{
protected:
	int id;
	float x, y;
	int currentVita, maxVita;
	int price;
	int tickFleet;
public:
	Fleet(float x_, float y_) :
		x(x_),
		y(y_),
		tickFleet(0){}
	virtual void draw() = 0;
	void drawVita();
	float getX();
	float getY();
	int getId();
	int getPrice();
	int getCurrentVita();
	int getMaxVita();
	int getTickFleet();
	void drawPrice();
	void drawSelect();
	virtual void drawDescription() = 0;
	void incrTickFleet();
	void setCurrentVita(int newCurrentVita);
	void removeVitaFleet(int power);
	bool isDied();
};

