
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			gameboards[i][j]->draw();
		}
		
	}

	for (int i = 0; i < (int)fleets->size(); i++) {
		(*fleets)[i]->draw();
		(*fleets)[i]->drawVita();
	}

	for (int i = 0; i < (int)fires->size(); i++) {
		(*fires)[i]->draw();
	}
	
	for (int i = 0; i < (int)asteroids->size(); i++) {
		(*asteroids)[i]->draw();
	}

	/*Affichage des choix de vaisseaux*/
	for (int i = 0; i < (int)fleetsChoice->size(); i++) {
		(*fleetsChoice)[i]->draw();
	}

	(*gameManagement).drawMoney();
	(*gameManagement).drawLife();
}

