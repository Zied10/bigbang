#pragma once

#include "Engine.h"
#include "Gameboard.h"
#include "Cruiser.h"
#include "Fleet.h"
#include "Laser.h"
#include "Gauss.h"
#include "Fire.h"
#include "Asteroid.h"
#include "LittleAsteroid.h"
#include "GameManagement.h"

class MyGameEngine:public GameEngine {
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> *fleets;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;
	GameManagement *gameManagement;

public:
    int tick;
	MyGameEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_, GameManagement *gameManagement_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fires(fires_),
		asteroids(asteroids_),
		gameManagement(gameManagement_),
		tick(0){}
    
    virtual void idle();
    
};
