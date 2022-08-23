#pragma once
class Chest
{
private:
	char chestIcon;
	int x;
	int y;
	int moneyReward;
public:
	Chest(int xpos, int ypos);
	void getX();
	void getY();
};

