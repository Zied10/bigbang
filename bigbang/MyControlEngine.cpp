
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){

		float posX = (x - 300) / 300.f;
		float posY = (y - 300) / -300.f;
		int i = (int)((posX + 1) / 0.183f) - 1;
		int j = (int)((posY + 1) / 0.183f) - 1;

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if ((*gameMode) == GameMode::INTRO){
				(*gameMode) = GameMode::IN_GAME;
			}

			else if ((*gameMode) == GameMode::FINISH){
				(*fleetSelect).setId(0);
				(*fleetSelect).setPrice(0);

				for (int line = 0; line < 10; line++){
					for (int column = 0; column < 10; column++){
						if (gameboards[line][column]->getNbClick()){
							Gameboard::rmClick(gameboards, gameboards[line][column]->getPosX(), gameboards[line][column]->getPosY());
						}
					}
				}
				(*gameManagement).resetGame();
				(*gameMode) = GameMode::INTRO;
			}
			else{
				if (posX > -0.817 && posY > -0.817){
					if (!gameboards[i][j]->getNbClick() && (*gameManagement).getMoney() >= (*fleetSelect).getPrice() && (*fleetSelect).getPrice() > 0){
							gameboards[i][j]->addClick();
							(*gameManagement).removeMoney((*fleetSelect).getPrice());
							switch ((*fleetSelect).getId()){
							case 1:
								fleets->push_back(new Cruiser(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
								break;
							case 2:
								fleets->push_back(new Bomber(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
								break;
							case 3:
								fleets->push_back(new Destroyer(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
								break;
							case 4:
								fleets->push_back(new Shield(gameboards[i][j]->getPosX(), gameboards[i][j]->getPosY()));
								break;
							}
					}
				}
				else{
					for (int i = 0; i < (int)fleetsChoice->size(); i++){
						if (posX >(*fleetsChoice)[i]->getX() && posX < ((*fleetsChoice)[i]->getX() + 0.15) && posY >(*fleetsChoice)[i]->getY() && posY < ((*fleetsChoice)[i]->getY() + 0.18)){
							(*fleetSelect).setId((*fleetsChoice)[i]->getId());
							(*fleetSelect).setPrice((*fleetsChoice)[i]->getPrice());
						}
					}
				}

				if ((*gameMode) == GameMode::WAIT_WAVE && posX >= 0.82 && posX <= 0.97 && posY >= -0.97 && posY <= -0.85){
					(*gameManagement).addLevel();
					(*gameMode) = IN_GAME;
				}
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {

			if (posX > -0.817 && posY > -0.817 && gameboards[i][j]->getNbClick()){
				for (int k = 0; k < (int)fleets->size(); k++){
					if ((*fleets)[k]->getX() == gameboards[i][j]->getPosX() && (*fleets)[k]->getY() == gameboards[i][j]->getPosY()){
						Gameboard::rmClick(gameboards, (*fleets)[k]->getX(), (*fleets)[k]->getY());
						(*gameManagement).addMoney((*fleets)[k]->getPrice() / 2);
						delete (*fleets)[k];
						(*fleets).erase((*fleets).begin() + k);
					}
				}
			}
		}
}