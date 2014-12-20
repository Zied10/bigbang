#pragma once
#include "Utility.h"
#include "GraphicPrimitives.h"

class GameManagement
{
private:
	int money;
	int life;
	int level;
	int nbCurrentAste;
public:
	GameManagement():money(100),life(5),level(1),nbCurrentAste(0){}
	void addMoney(int earnedMoney);
	void removeMoney(int spentMoney);
	void drawMoney();
	void drawLife();
	void drawNextWave();
	void drawLevel();
	void drawEnd();
	void drawIntro();
	void removeLife();
	void addLevel();
	void resetGame();
	void drawProgression();
	void setNbCurrentAste(int n);
	int getMoney();
	int getLife();
	int getLevel();
	int nbMaxLittleAste();
	int nbMaxMiddleAste();
	int nbMaxBigAste();
	
};

