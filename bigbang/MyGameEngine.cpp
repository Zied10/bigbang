
#include "MyGameEngine.h"


void MyGameEngine::idle(){


	/*Collision asteroide avec vaisseaux*/

	for (int i = 0; i < (int)asteroids->size(); i++) {
		bool yetTouched = false;
		if ((*asteroids)[i]->getX() < -0.85f){
			yetTouched = true;
			delete (*asteroids)[i];
			(*asteroids).erase((*asteroids).begin() + i);
		}
		for (int j = 0; j < (int)fleets->size(); j++){
			if ((*asteroids)[i]->touchFleet(*(*fleets)[j])){
				yetTouched = true;
				delete (*asteroids)[i];
				(*asteroids).erase((*asteroids).begin() + i);
				if ((*fleets)[j]->isDied()){
					Gameboard::rmClick(gameboards, (*fleets)[j]->getX(), (*fleets)[j]->getY());
					delete (*fleets)[j];
					(*fleets).erase((*fleets).begin() + j);
				}
				break;
			}
		}
		if (!yetTouched){
			(*asteroids)[i]->tick();
		}
	}

	/*  Creation des tirs pour les vaisseaux   */
	if ((tick % 100) == 0){
		for (int i = 0; i < (int)fleets->size(); i++) {
			fires->push_back(new Laser((*fleets)[i]->getX(), (*fleets)[i]->getY()));
		}
	}

	/* Collision entre tirs et asteroides */
	for (int i = 0; i < (int)fires->size(); i++) {
		bool yetTouched = false;
		for (int j = 0; j < (int)asteroids->size(); j++){
			if ((*fires)[i]->touchAsteroid(*(*asteroids)[j])){
				yetTouched = true;
				delete (*fires)[i];
				(*fires).erase((*fires).begin() + i);
				if ((*asteroids)[j]->isDied()){
					delete (*asteroids)[j];
					(*asteroids).erase((*asteroids).begin() + j);
				}
				break;
			}
		}
		if ((*fires)[i]->getX() > 1.0f){
			yetTouched = true;
			delete (*fires)[i];
			(*fires).erase((*fires).begin() + i);
			break;
		}
		if (!yetTouched){
			(*fires)[i]->tick();
		}
	}

	/* Creation d'asteroides */
	if ((tick % 200) == 0){
		//asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * 5)));
		asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * (rand() % 10))));
	}
	tick++;
}