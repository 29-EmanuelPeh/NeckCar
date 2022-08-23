#include "Chest.h"
#include <random>
Chest::Chest(int xpos, int ypos):x(xpos), y(ypos)
{
	chestIcon = 'C';
	moneyReward = rand() % 11 + 20;
}
