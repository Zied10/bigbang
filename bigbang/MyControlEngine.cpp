
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){

	float posX = (x-300) / 300.f;
	float posY = (y-300)/ -300.f;
	int i = (int)((posX + 1) / 0.183f) - 1;
	int j = (int)((posY + 1) / 0.183f) - 1;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (posX > -0.817 && posY > -0.817){
			if (!gameboards[i][j]->getNbClick()){
				gameboards[i][j]->addClick();
				fleets->push_back(new Cruiser(1, gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	}
}