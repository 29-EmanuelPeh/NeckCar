#include "Chest.h"
#include <random>

Chest::Chest(int xpos, int ypos):x(xpos), y(ypos)
{
	chestIcon = 'C';
	moneyReward = rand() % 11 + 10;
}

int Chest::getX()
{
	return x;
}

int Chest::getY()
{
	return y;
}

char Chest::getchestIcon()
{
	return chestIcon;
}

int Chest::open()
{
	chestIcon = '.';
	return moneyReward;
}
