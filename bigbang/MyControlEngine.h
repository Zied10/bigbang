#pragma once
#include "Engine.h"
#include "Gameboard.h"
#include "Fleet.h"
#include "Cruiser.h"

class MyControlEngine:public ControlEngine {
    std::vector<Fleet * > *fleets;
	std::vector<std::vector<Gameboard *> > gameboards;

public:
	MyControlEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_) :
		gameboards(gameboards_),
		fleets(fleets_)
		{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
