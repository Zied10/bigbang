#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Fourmi.h"
#include "Carre.h"
#include "Chasseur.h"
#include "Vaisseau.h"
#include "Laser.h"
#include "Fire.h"
#include "Asteroid.h"
#include "LittleAsteroid.h"

class MyGameEngine:public GameEngine {
	std::vector<std::vector<Carre *> > carres;
	std::vector<Vaisseau *> *vaisseaux;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;

public:
    int tick;
	MyGameEngine(std::vector<std::vector<Carre *> > carres_, std::vector<Vaisseau *> *vaisseaux_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_) :
		carres(carres_),
		vaisseaux(vaisseaux_),
		fires(fires_),
		asteroids(asteroids_),
		tick(0){}
    
    virtual void idle();
    
};
