#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Gameboard.h"
#include "Cruiser.h"
#include "Fleet.h"
#include "Laser.h"
#include "Fire.h"
#include "Asteroid.h"
#include "LittleAsteroid.h"


class MyGraphicEngine:public GraphicEngine {
    
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> *fleets;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;
    
    char * str;
public:
    
	MyGraphicEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fires(fires_),
		asteroids(asteroids_)
        {}
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
};
