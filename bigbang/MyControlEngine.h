#pragma once
#include "Engine.h"
#include "Gameboard.h"
#include "Fleet.h"
#include "Cruiser.h"
#include "Bomber.h"
#include "FleetSelect.h"

class MyControlEngine:public ControlEngine {
    std::vector<Fleet * > *fleets;
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet * > *fleetsChoice;
	FleetSelect fleetSelect;

public:
	MyControlEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fleet *> *fleetsChoice_, FleetSelect fleetSelect_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fleetsChoice(fleetsChoice_),
		fleetSelect(fleetSelect_)
		{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
