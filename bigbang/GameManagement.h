#pragma once
#include "Utility.h"
#include "GraphicPrimitives.h"

class GameManagement
{
private:
	int money;
	int life;
	int level;
public:
	GameManagement():money(50),life(5),level(1){}
	void addMoney(int earnedMoney);
	void removeMoney(int spentMoney);
	int getMoney();
	void drawMoney();
	void drawLife();
	int getLife();
	void removeLife();
	int getLevel();
	void addLevel();
	~GameManagement();
};

