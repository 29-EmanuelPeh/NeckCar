#pragma once
class Chest
{
private:
	char chestIcon = 'C';
	int x;
	int y;
	int moneyReward;
public:
	Chest();
	int getX();
	void setX(int px);
	int getY();
	void setY(int py);
	char getchestIcon();
	int open();
};

