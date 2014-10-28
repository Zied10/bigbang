#pragma once
#include "GraphicPrimitives.h"
#include "Fleet.h"
class Asteroid
{
protected:
	float x, y, size;
	int vita, power;
	static int numberAste;
public:
	Asteroid(float y_) :
		x(1.01f),
		y(y_){
		addNumberAste();
	}
	float getX();
	float getY();
	int getVita();
	void removeVita(int power);
	bool isDied();
	virtual void tick() = 0;
	void draw();
	bool touchFleet(Fleet& fleet);
	static int getNumberAste();
	void addNumberAste();
	static void resetNumberAste();
	~Asteroid();
};

