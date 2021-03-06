#pragma once

#include "Engine.h"
#include "Gameboard.h"
#include "Fleet.h"
#include "Plasma.h"
#include "Laser.h"
#include "Gauss.h"
#include "Fire.h"
#include "Asteroid.h"
#include "LittleAsteroid.h"
#include "MiddleAsteroid.h"
#include "BigAsteroid.h"
#include "GameManagement.h"
#include "GameMode.h"
#include <chrono>

class MyGameEngine:public GameEngine {
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> *fleets;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;
	GameManagement *gameManagement;
	GameMode *gameMode;
	std::chrono::system_clock::time_point tStart_ = std::chrono::high_resolution_clock::now();
	int nbLittleAste, nbMiddleAste, nbBigAste;

public:
    int tick;
	MyGameEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_, GameManagement *gameManagement_, GameMode *gameMode_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fires(fires_),
		asteroids(asteroids_),
		gameManagement(gameManagement_),
		gameMode(gameMode_),
		nbLittleAste(0),
		nbMiddleAste(0),
		nbBigAste(0),
		tick(0){}
    
    virtual void idle();
	void collisionAsteFleet();
	void creationFire();
	void collisionFireAste();
	void creationAste(int t);
	void incrTick();
	void incrAllTicks();
	void resetNbAste();
    
};
