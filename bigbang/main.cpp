

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv, 600, 600, "Big Bang");
    
	std::vector<std::vector<Gameboard *> > gameboards;
	std::vector<Fleet *> fleets;
	std::vector<Fire *> fires;
	std::vector<Asteroid *> asteroids;

	for (int line = 0; line < 10; line++){
		gameboards.emplace_back();
		for (int column = 0; column < 10; column++)
		if ((line + column) % 2){
			gameboards[line].push_back(new Gameboard(-0.817 + line * 0.183f, -0.817f + column * 0.183f, 0.183f, 1.0f));
		}
		else{
			gameboards[line].push_back(new Gameboard(-0.817 + line * 0.183f, -0.817f + column * 0.183f, 0.183f, 0.5f));
		}
	}

    GraphicEngine * ge = new MyGraphicEngine(gameboards, &fleets, &fires, &asteroids);
	GameEngine * gme = new MyGameEngine(gameboards, &fleets,&fires, &asteroids);
	ControlEngine * ce = new MyControlEngine(gameboards, &fleets);
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
