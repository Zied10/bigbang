#include "GameManagement.h"


void GameManagement::addMoney(int earnedMoney){
	money += earnedMoney;
}

void GameManagement::removeMoney(int spentMoney){
	money -= spentMoney;
}

int GameManagement::getMoney(){
	return money;
}

void GameManagement::drawMoney(){
	char* charMoney = new char[100];
	char* textMoney = "Gold : ";
	Utility::itoa(money, charMoney);
	GraphicPrimitives::drawText2D(textMoney, -0.99, 0.9, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(charMoney, -0.97, 0.8, 1.0f, 1.0f, 1.0f);
	delete[] charMoney;
}

void GameManagement::drawNextWave(){
	GraphicPrimitives::drawFillRect2D(0.82, -0.97, 0.15, 0.12, 1., 1., 1.);
	GraphicPrimitives::drawText2D(">>", 0.865, -0.93, 0.0f, 0.0f, 0.0f);
}

void GameManagement::drawEnd(){
	char* charScore = new char[100];
	Utility::itoa(level, charScore);
	GraphicPrimitives::drawText2D("GAME OVER", -0.2, 0.5, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("You resisted until the wave", -0.4, 0.2, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(charScore, 0.38, 0.2, 1.0f, .0f, .0f);
	GraphicPrimitives::drawText2D("Clique sur la page pour rejouer !", -0.4, -0.9, 0.8f, 0.8f, 0.8f);
}

void GameManagement::drawIntro(){
	GraphicPrimitives::drawText2D("THE BIG BANG ATTACK", -0.4, 0.8, .0f, .6f, 1.0f);
	GraphicPrimitives::drawText2D("De nombreux asteroides approchent de la Terre.", -0.9, 0.5, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("Etant le commandant supreme, tu es charge de proteger la planete.", -0.9, 0.4, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("Tu as pour ca a ta disposition 4 sortes de vaisseaux.", -0.9, 0.3, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("Chaque vaisseau a ses propres caracterisques.", -0.9, 0.2, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("Fais preuve de strategie car le sort de la planete est en jeu.", -0.9, 0.1, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("La Terre compte sur toi !!!", -0.35, -0.2, .7f, .0f, .0f);
	GraphicPrimitives::drawText2D("Clique sur la page quand tu te sens pret !", -0.6, -0.9, .8f, .8f, .8f);

}

int GameManagement::getLife(){
	return life;
}

void GameManagement::removeLife(){
	life -= 1;
}

void GameManagement::drawLife(){
	GraphicPrimitives::drawText2D("Life :", -0.98, -0.40, 1.0f, 1.0f, 1.0f);
	for (int i = 1; i <= 5; i++){
		GraphicPrimitives::drawFillRect2D(-0.98, -0.75f + i * 0.05, 0.14f, 0.040f, 1.f, 0.f, 0.f);
		if (life >= i){
			GraphicPrimitives::drawFillRect2D(-0.98, -0.75f + i * 0.05, 0.14f, 0.040f, 0.f, 1.f, 0.f);
		}
	}
}

void GameManagement::drawLevel(){
	GraphicPrimitives::drawText2D("Wave:", -0.98, -0.88, 1.0f, 1.0f, 1.0f);
	char* charLevel = new char[100];
	Utility::itoa(level, charLevel);
	GraphicPrimitives::drawText2D(charLevel, -0.80, -0.88, 1.0f, 1.0f, 1.0f);
	delete[] charLevel;
}

void GameManagement::addLevel(){
	level += 1;
}

int GameManagement::getLevel(){
	return level;
}

int GameManagement::nbMaxLittleAste(){
	if (level < 4){
		return level * 3;
	}
	return level;
}

int GameManagement::nbMaxMiddleAste(){
	if (level < 3){
		return 0;
	}
	else if (level < 7){
		return level - 2;
	}
	else if (level < 12){
		return level + 3;
	}
	return 0;
}

int GameManagement::nbMaxBigAste(){
	if (level < 7){
		return 0;
	}
	else if (level < 10){
		return level - 7;
	}
	else return level - 5;
}

void GameManagement::resetGame(){
	level = 1;
	money = 100;
	life = 5;
}

void GameManagement::drawProgression(){
	int maxAste = nbMaxBigAste() + nbMaxMiddleAste() + nbMaxLittleAste();
	float rapport = ((float)nbCurrentAste / (float)maxAste);
	GraphicPrimitives::drawFillRect2D(-0.5, -0.98, 1, 0.05, .4f, 0.4f, 0.4f);
	GraphicPrimitives::drawFillRect2D(-0.5, -0.98, rapport, 0.05, .8f, 0.8f, 0.8f);
}

void GameManagement::setNbCurrentAste(int n){
	nbCurrentAste = n;
}