
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	for (int i = 0; i < asteroids->size(); i++) {
		
		(*asteroids)[i]->tick();
	}	
    if((tick % 100) == 0){
		for (int i = 0; i < vaisseaux->size(); i++) {
			fires->push_back(new Laser((*vaisseaux)[i]->getX(), (*vaisseaux)[i]->getY(), 0.01f));
		}  	
	}
		for (int i = 0; i < fires->size(); i++) {
			bool x = false;
			for (int j = 0; j < asteroids->size(); j++){
				if ((*fires)[i]->touchAsteroid(*(*asteroids)[j])){
					x = true;
					delete (*fires)[i];
					(*fires).erase((*fires).begin() + i);
					if ((*asteroids)[j]->isDied()){
						delete (*asteroids)[j];
						(*asteroids).erase((*asteroids).begin() + j);
					}
				}
			}
			if (!x){
				(*fires)[i]->tick();
			}
	}
	if ((tick % 400 ) == 0){
		asteroids->push_back(new LittleAsteroid(-0.817 + (0.183 * (rand() % 10))));
	}
tick++;
}