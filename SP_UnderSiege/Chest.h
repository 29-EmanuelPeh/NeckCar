#pragma once
class Chest
{
private:
	char chestIcon = 'C';
	int x;
	int y;
	int moneyReward;
public:
	Chest(int xpos, int ypos);
	int getX();
	int getY();
	char getchestIcon();
	int open();
};

