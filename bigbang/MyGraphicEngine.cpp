
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){

	if ((*gameMode) != GameMode::FINISH && (*gameMode) != GameMode::INTRO){
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
			if ((*fleetSelect).getId() == (*fleetsChoice)[i]->getId()){
				(*fleetsChoice)[i]->drawSelect();
				(*fleetsChoice)[i]->drawDescription();
			}
			(*fleetsChoice)[i]->draw();
			(*fleetsChoice)[i]->drawPrice();

		}

		(*gameManagement).drawMoney();
		(*gameManagement).drawLife();
		(*gameManagement).drawLevel();
		(*gameManagement).drawProgression();

		if ((*gameMode) == GameMode::WAIT_WAVE){
			(*gameManagement).drawNextWave();
		}
	}
	else if ((*gameMode) == GameMode::INTRO){
		(*gameManagement).drawIntro();
	}
	else
		(*gameManagement).drawEnd();
}

