#pragma once

#include "Engine.h"
#include "Gameboard.h"
#include "Cruiser.h"
#include "Fleet.h"
#include "Laser.h"
#include "Fire.h"
#include "Asteroid.h"
#include "LittleAsteroid.h"

class MyGameEngine:public GameEngine {
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> *fleets;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;

public:
    int tick;
	MyGameEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fires(fires_),
		asteroids(asteroids_),
		tick(0){}
    
    virtual void idle();
    
};
