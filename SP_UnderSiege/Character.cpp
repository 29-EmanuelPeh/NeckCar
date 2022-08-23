#include "Character.h"
#include <Windows.h>
#include <iostream>

Character::Character()
{
	health = 100;
	damage = 5;
	range = 1;
    money = 0;
	x = 1;
	y = 1;
    canAttack = false;
    for (int i = 0; i < inventorySize; i++)
    {
        inventory[i] = nullptr;
    }
}

void Character::PrintStat(void)
{
    std::cout << "Player HP: " << health << "  AttackPt: " << damage << std::endl << std::endl;
}

void Character::addInventory(Object* object)
{
    if (currentCapacity >= inventorySize)
    {
        return;
    }
    inventory[currentCapacity++] = object;
}

void Character::printInventory()
{
    for (int i = 0; i < inventorySize; i++)
    {
        if (inventory[i] == nullptr)
        {
            continue;
        }
        std::cout << inventory[i]->getPrice() << std::endl;
    }
}

int Character::getX()
{
	return x;
}

void Character::setX()
{

}

int Character::getY()
{
	return y;
}

void Character::setY()
{
}

int Character::getHealth()
{
    return health;
}

void Character::setHealth(int h)
{
    //check if health is not 0 or 100, set to new value
    if ((h >= 0) && (h <= 100))
        health = h;
    //check if health is negative, set it to 0
    else if (h <= 0)
        health = 0;
    //check if health is over 100, set it to 100
    else if (h >= 100)
        health = 100;
}

int Character::getDamage()
{
    return 0;
}

int Character::getRange()
{
    return 0;
}

int& Character::getMoney()
{
    return money;
}

void Character::move(char dir)
{
	switch (dir)
	{
	case 'w':
		x--;
		break;
	case 's':
		x++;
		break;
	case 'a':
		y--;
		break;
	case 'd':
		y++;
		break;
	default:
		break;
	}
}

bool Character::checkDir(char dir, Character* enemy)
{
    if (enemy != NULL)
    {
        //check what direction player chose to attack
        switch (dir)
        {
        case 'i':
            //check if that direction has a enemy for attacking
            if (x - 1 == enemy->x && y == enemy->y)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 'k':
            //check if that direction has a enemy for attacking
            if (x + 1 == enemy->x && y == enemy->y)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 'j':
            //check if that direction has a enemy for attacking
            if (x == enemy->x && y - 1 == enemy->y)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 'l':
            //check if that direction has a enemy for attacking
            if (x == enemy->x && y + 1 == enemy->y)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
            break;
        }
    }
    else
    {
        return false;
    }
}

void Character::attack(Character* enemy)
{
    int temp = enemy->getHealth();
    enemy->setHealth(temp - damage);
}

Character::~Character()
{
}
