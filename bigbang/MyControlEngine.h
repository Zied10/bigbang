#pragma once
#include "Engine.h"
#include "Gameboard.h"
#include "Fleet.h"
#include "Cruiser.h"
#include "Bomber.h"
#include "FleetSelect.h"
#include "GameManagement.h"

class MyControlEngine:public ControlEngine {
    std::vector<Fleet * > *fleets;
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet * > *fleetsChoice;
	FleetSelect fleetSelect;
	GameManagement *gameManagement;

public:
	MyControlEngine(std::vector<std::vector<Gameboard *> > gameboards_, std::vector<Fleet *> *fleets_, std::vector<Fleet *> *fleetsChoice_, FleetSelect fleetSelect_, GameManagement *gameManagement_) :
		gameboards(gameboards_),
		fleets(fleets_),
		fleetsChoice(fleetsChoice_),
		fleetSelect(fleetSelect_),
		gameManagement(gameManagement_)
		{}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
