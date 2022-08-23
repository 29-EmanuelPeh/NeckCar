#include "Boss.h"

Boss::Boss()
{
	Health = 1000;
	Damage = 10;
	x = 50;
	y = 60;
}

int Boss::getX()
{
	return x;
}

int Boss::getY()
{
	return y;
}

void Boss::attack(int worldX, int worldY)
{

}
