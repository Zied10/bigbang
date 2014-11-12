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

int GameManagement::getLife(){
	return life;
}

void GameManagement::removeLife(){
	life -= 1;
}

void GameManagement::drawLife(){
	GraphicPrimitives::drawText2D("Life :", -0.98, -0.96, 1.0f, 1.0f, 1.0f);
	for (int i = 1; i <= 5; i++){
		GraphicPrimitives::drawFillRect2D(-0.89f + i*0.05, -0.975f, 0.03f, 0.096f, 1.f, 0.f, 0.f);
		if (life >= i){
			GraphicPrimitives::drawFillRect2D(-0.89f + i*0.05, -0.975f, 0.03f, 0.096f, 0.f, 1.f, 0.f);
		}
	}
}

void GameManagement::addLevel(){
	level += 1;
}

int GameManagement::getLevel(){
	return level;
}
