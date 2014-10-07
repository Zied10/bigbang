

#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv, 600, 600, "Big Bang");
    
	std::vector<std::vector<Carre *> > carres;
	std::vector<Vaisseau *> vaisseaux;
	std::vector<Fire *> fires;
	std::vector<Asteroid *> asteroids;

	for (int line = 0; line < 10; line++){
		carres.emplace_back();
		for (int column = 0; column < 10; column++)
		if ((line + column) % 2){
			carres[line].push_back(new Carre(-0.817 + line * 0.183f, -0.817f + column * 0.183f, 0.183f, 1.0f));
		}
		else{
			carres[line].push_back(new Carre(-0.817 + line * 0.183f, -0.817f + column * 0.183f, 0.183f, 0.5f));
		}
	}

    GraphicEngine * ge = new MyGraphicEngine(carres, &vaisseaux, &fires, &asteroids);
	GameEngine * gme = new MyGameEngine(carres, &vaisseaux,&fires, &asteroids);
	ControlEngine * ce = new MyControlEngine(carres, &vaisseaux);
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
