
#include "MyGameEngine.h"


void MyGameEngine::idle(){

	switch ((*gameMode)){
	case IN_GAME:
		collisionAsteFleet();
		creationFire();
		collisionFireAste();
		creationAste(1600);
		if (Asteroid::getNumberAste() == 5){
			(*gameMode) = WAIT_WAVE;
		}
		tick++;
		break;


	case PAUSE:
		break;

	case WAIT_WAVE:
		collisionAsteFleet();
		creationFire();
		collisionFireAste();
		tick++;
		break;

	case FINISH:
		break;
	}

		
	}

/*Collision asteroide avec vaisseaux*/
void MyGameEngine::collisionAsteFleet(){
	for (int i = 0; i < (int)asteroids->size(); i++) {
		bool yetTouched = false;
		if ((*asteroids)[i]->getX() < -0.85f){
			yetTouched = true;
			(*gameManagement).removeLife();
			delete (*asteroids)[i];
			(*asteroids).erase((*asteroids).begin() + i);
		}
		for (int j = 0; j < (int)fleets->size(); j++){
			if ((*asteroids)[i]->touchFleet(*(*fleets)[j])){
				yetTouched = true;
				(*asteroids)[i]->removeVita((*fleets)[j]->getMaxVita());
				if ((*asteroids)[i]->isDied()){
					delete (*asteroids)[i];
					(*asteroids).erase((*asteroids).begin() + i);
				}
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
}

/*  Creation des tirs pour les vaisseaux   */
void MyGameEngine::creationFire(){
	if ((*asteroids).size() > 0){
		for (int i = 0; i < (int)fleets->size(); i++) {
			switch ((*fleets)[i]->getId())
			{
			case 1:
				if ((tick % 550) == 0){
					fires->push_back(new Laser((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					break;
				}
				else break;
			case 2:
				if ((tick % 800) == 0){
					fires->push_back(new Gauss((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					break;
				}
				else break;
			}
		}
	}
}

void MyGameEngine::collisionFireAste(){
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
					(*gameManagement).addMoney(5);
				}
				break;
			}
		}
		if ((*fires)[i]->getX() > 1.01f){
			yetTouched = true;
			delete (*fires)[i];
			(*fires).erase((*fires).begin() + i);
			break;
		}
		if (!yetTouched){
			(*fires)[i]->tick();
		}
	}
}

/* Creation d'asteroides */
void MyGameEngine::creationAste(int t){
	if ((tick % t) == 0){
		asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * 5)));
		asteroids->push_back(new MiddleAsteroid(-0.817 + (0.183 * 6)));
		asteroids->push_back(new BigAsteroid(-0.817 + (0.183 * 7)));
		//asteroids->push_back(new MiddleAsteroid(-0.817 + (0.183 * (rand() % 10))));
	}
}