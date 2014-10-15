
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	float posX = (x-300) / 300.f;
	float posY = (y-300)/ -300.f;
	int i = (int)((posX + 1) / 0.183f) - 1;
	int j = (int)((posY + 1) / 0.183f) - 1;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (posX > -0.817 && posY > -0.817){
			if (!gameboards[i][j]->getNbClick()){
				switch (fleetSelect.getId()){
				case 1 :
					gameboards[i][j]->addClick();
					fleets->push_back(new Cruiser(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
					break;
				case 2:
					gameboards[i][j]->addClick();
					fleets->push_back(new Bomber(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
					break;
				}
			}
		}
		else{
			for (int i = 0; i < (int)fleetsChoice->size(); i++){
				if (posX > (*fleetsChoice)[i]->getX() && posX < ((*fleetsChoice)[i]->getX() + 0.15) && posY > (*fleetsChoice)[i]->getY() && posY < ((*fleetsChoice)[i]->getY() + 0.18)){
					std::cout << (*fleetsChoice)[i]->getId() << std::endl;
					fleetSelect.setId((*fleetsChoice)[i]->getId());
				}
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	}
}