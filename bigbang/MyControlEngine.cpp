
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	float posX = (x-300) / 300.f;
	float posY = (y-300)/ -300.f;
	int i = (int)((posX + 1) / 0.183f) - 1;
	int j = (int)((posY + 1) / 0.183f) - 1;
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	   if (!carres[i][j]->getNbClick()){
	   carres[i][j]->addClick();
	   vaisseaux->push_back(new Chasseur(carres[i][j]->getPosX(), carres[i][j]->getPosY(), 10, 0.1f));
	   }
    }
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
   }
}