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
}


GameManagement::~GameManagement()
{
}
