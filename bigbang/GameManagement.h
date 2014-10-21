#pragma once
#include "Utility.h"
#include "GraphicPrimitives.h"

class GameManagement
{
private:
	int money;
public:
	GameManagement():money(50){}
	void addMoney(int earnedMoney);
	void removeMoney(int spentMoney);
	int getMoney();
	void drawMoney();
	~GameManagement();
};

