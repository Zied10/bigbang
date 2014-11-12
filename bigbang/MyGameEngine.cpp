
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	std::chrono::system_clock::time_point tNow = std::chrono::high_resolution_clock::now();
	int currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tStart_).count();
	if (currentTime >= 15){

		switch ((*gameMode)){
		case IN_GAME:
			collisionAsteFleet();
			creationFire();
			collisionFireAste();
			creationAste(100);
			
			if (Asteroid::getNumberAste() == 10){
				(*gameMode) = WAIT_WAVE;
			}
			if ((*gameManagement).getLife() == 0){
				(*gameMode) = FINISH;
			}
			incrAllTicks();
			break;


		case PAUSE:
			break;

		case WAIT_WAVE:
			collisionAsteFleet();
			creationFire();
			collisionFireAste();
			incrAllTicks();
			break;

		case FINISH:
			break;
		}
		tStart_ = std::chrono::high_resolution_clock::now();
	}
		
}

/*Collision asteroide avec vaisseaux*/
void MyGameEngine::collisionAsteFleet(){
	for (int i = 0; i < (int)asteroids->size(); i++) {
		bool yetTouched = false;
		if ((*asteroids)[i]->getX() < -0.817f){
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
				if (((*fleets)[i]->getTickFleet() % 100) == 0){
					fires->push_back(new Laser((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					break;
				}
				else break;
			case 2:
				if (((*fleets)[i]->getTickFleet() % 150) == 0){
					fires->push_back(new Gauss((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					break;
				}
				else break;
			case 3:
				if (((*fleets)[i]->getTickFleet() % 250) == 0){
					fires->push_back(new Plasma((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					if ((*fleets)[i]->getY() < 0.8){
						fires->push_back(new Plasma((*fleets)[i]->getX(), (*fleets)[i]->getY() + 0.183));
					}
					if ((*fleets)[i]->getY() > -0.63){
						fires->push_back(new Plasma((*fleets)[i]->getX(), (*fleets)[i]->getY() - 0.183));
					}
					break;
				}
				else break;
			}
		}
	}
}

/* Collision entre tirs et asteroides */
void MyGameEngine::collisionFireAste(){
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
		//asteroids->push_back(new MiddleAsteroid(-0.817 + (0.183 * 6)));
		//asteroids->push_back(new BigAsteroid(-0.817 + (0.183 * 7)));
		//asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * (rand() % 10))));
	}
}

void MyGameEngine::incrAllTicks(){
	for (int i = 0; i < (int)fleets->size(); i++) {
		(*fleets)[i]->incrTickFleet();
	}
	tick++;
}