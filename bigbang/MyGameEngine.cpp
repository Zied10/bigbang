
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	for (int i = 0; i < asteroids->size(); i++) {
		
		(*asteroids)[i]->tick();
	}	
    if((tick % 100) == 0){
		for (int i = 0; i < fleets->size(); i++) {
			fires->push_back(new Laser((*fleets)[i]->getX(), (*fleets)[i]->getY(), 0.01f));
		}  	
	}
		for (int i = 0; i < fires->size(); i++) {
			bool yetTouched = false;
			for (int j = 0; j < asteroids->size(); j++){
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
				if ((*fires)[i]->getX() > 1.0f){
					yetTouched = true;
					delete (*fires)[i];
					(*fires).erase((*fires).begin() + i);
				}
			}
			if (!yetTouched){
				(*fires)[i]->tick();
			}
	}
	if ((tick % 200 ) == 0){
		//asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * 5)));
		asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * (rand() % 10))));
	}
tick++;
}