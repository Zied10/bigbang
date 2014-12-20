
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	std::chrono::system_clock::time_point tNow = std::chrono::high_resolution_clock::now();
	int currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tStart_).count();
	if (currentTime >= 15){

		switch ((*gameMode)){
		case INTRO:
			break;
		case IN_GAME:
			collisionAsteFleet();
			creationFire();
			collisionFireAste();
			creationAste(100);
			
			if ((nbLittleAste + nbMiddleAste + nbBigAste) >=
				(*gameManagement).nbMaxLittleAste() + (*gameManagement).nbMaxMiddleAste() + (*gameManagement).nbMaxBigAste() &&
				(*asteroids).size() == 0)
			{
				(*gameMode) = WAIT_WAVE;
			}
			if ((*gameManagement).getLife() == 0){
				(*gameMode) = FINISH;
			}
			incrAllTicks();
			break;

		case WAIT_WAVE:
			collisionAsteFleet();
			creationFire();
			collisionFireAste();
			incrAllTicks();
			resetNbAste();
			break;

		case FINISH:
			for (int i = 0; i < (int)asteroids->size(); i++) {
				delete (*asteroids)[i];
				(*asteroids).erase((*asteroids).begin() + i);
			}

			for (int j = 0; j < (int)fleets->size(); j++){
				delete (*fleets)[j];
				(*fleets).erase((*fleets).begin() + j);
			}

			for (int i = 0; i < (int)fires->size(); i++) {
				delete (*fires)[i];
				(*fires).erase((*fires).begin() + i);
			}
			resetNbAste();
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
				if (((*fleets)[i]->getTickFleet() % 250) == 0){
					fires->push_back(new Gauss((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					break;
				}
				else break;
			case 3:
				if (((*fleets)[i]->getTickFleet() % 200) == 0){
					fires->push_back(new Plasma((*fleets)[i]->getX(), (*fleets)[i]->getY()));
					if ((*fleets)[i]->getY() < 0.8){
						fires->push_back(new Plasma((*fleets)[i]->getX(), (*fleets)[i]->getY() + 0.183));
					}
					if ((*fleets)[i]->getY() > -0.65){
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
		if (nbLittleAste < (*gameManagement).nbMaxLittleAste()){
			asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * (rand() % 10))));
			nbLittleAste++;
		}
		if (nbMiddleAste < (*gameManagement).nbMaxMiddleAste()){
			asteroids->push_back(new MiddleAsteroid(-0.817 + (0.183 * (rand() % 10))));
			nbMiddleAste++;
		}

		if (nbBigAste < (*gameManagement).nbMaxBigAste()){
			asteroids->push_back(new BigAsteroid(-0.817 + (0.183 * (rand() % 10))));
			nbBigAste++;
		}
		(*gameManagement).setNbCurrentAste(nbLittleAste + nbMiddleAste + nbBigAste);
	}
}

void MyGameEngine::incrAllTicks(){
	for (int i = 0; i < (int)fleets->size(); i++) {
		(*fleets)[i]->incrTickFleet();
	}
	tick++;
}

void MyGameEngine::resetNbAste(){
	nbLittleAste = 0;
	nbMiddleAste = 0;
	nbBigAste = 0;
	(*gameManagement).setNbCurrentAste(nbLittleAste + nbMiddleAste + nbBigAste);
}