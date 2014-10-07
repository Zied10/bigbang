
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			gameboards[i][j]->draw();
		}
		
	}

	for (int i = 0; i < fleets->size(); i++) {
		(*fleets)[i]->draw();
	}

	for (int i = 0; i < fires->size(); i++) {
		(*fires)[i]->draw();
	}
	
	for (int i = 0; i < asteroids->size(); i++) {
		(*asteroids)[i]->draw();
	}

}

