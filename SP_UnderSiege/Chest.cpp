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

void Chest::setX(int px)
{
	x = px;
}

int Chest::getY()
{
	return y;
}

void Chest::setY(int py)
{
	y = py;
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
