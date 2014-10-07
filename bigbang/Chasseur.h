#pragma once
#include "Vaisseau.h"
class Chasseur :
	public Vaisseau
{
public:
	Chasseur(float x, float y, int vita, float size) :Vaisseau(x, y, vita, size){
	}
	~Chasseur();
};

