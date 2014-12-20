#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Gameboard.h"
#include "Fleet.h"
#include "Fire.h"
#include "Asteroid.h"
#include "FleetSelect.h"
#include "GameManagement.h"
#include "GameMode.h"

class MyGraphicEngine:public GraphicEngine {
    
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> *fleets;
	std::vector<Fire *> *fires;
	std::vector<Asteroid *> *asteroids;
	std::vector<Fleet *> *fleetsChoice;
	FleetSelect *fleetSelect;
	GameManagement *gameManagement;
	GameMode *gameMode;
    
public:
    
	MyGraphicEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fire *> *fires_, std::vector<Asteroid *> *asteroids_, std::vector<Fleet *> *fleetsChoice_, FleetSelect *fleetSelect_, GameManagement *gameManagement_, GameMode *gameMode_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fires(fires_),
		asteroids(asteroids_),
		fleetsChoice(fleetsChoice_),
		fleetSelect(fleetSelect_),
		gameManagement(gameManagement_),
		gameMode(gameMode_)
        {}
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
};
