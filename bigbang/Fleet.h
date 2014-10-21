#pragma once
#include "GraphicPrimitives.h"
#include "Gameboard.h"
class Fleet
{
protected:
	int id;
	float x, y;
	int vita;
	int price;
public:
	Fleet(float x_, float y_) :
		x(x_),
		y(y_){}
	virtual void draw() = 0;
	virtual void drawVita() = 0;
	float getX();
	float getY();
	int getId();
	int getPrice();
	void setVita(int newVita);
	void removeVitaFleet(int power);
	bool isDied();
	~Fleet();
};

