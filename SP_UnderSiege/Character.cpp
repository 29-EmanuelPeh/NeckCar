#include "Character.h"
#include <Windows.h>
#include <iostream>

Character::Character()
{
	health = 100;
	damage = 10;
    armor = 0;
    healthpotion = 0;
	range = 1;
    money = 0;
	x = 1;
	y = 1;
    canAttack = false;
}

void Character::PrintStat(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, 0x0C);
    std::cout << "HP: " << health;
    SetConsoleTextAttribute(h, 0x03);
    std::cout << "  Armor: " << armor;
    SetConsoleTextAttribute(h, 0x0D);
    std::cout << "  AttackPt: " << damage;
    SetConsoleTextAttribute(h, 0x04);
    std::cout << "  HealthPotion: " << healthpotion;
    SetConsoleTextAttribute(h, 0x0E);
    std::cout << "  Money: " << money;
    SetConsoleTextAttribute(h, 0x0f);
    std::cout << "  X: " << x;
    std::cout << "  Y: " << y << std::endl << std::endl;

}

int Character::getX()
{
	return x;
}

void Character::setX(int px)
{
    x = px;
}

int Character::getY()
{
	return y;
}

void Character::setY(int py)
{
    y = py;
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

int Character::getArmor()
{
    return armor;
}

void Character::setArmor(int a)
{
    //check if armor is not 0 or 100, set to new value
    if (a <= 100)
        armor = a;
    //check if armor is over 100, set it to 100
    else if (a >= 100)
        armor = 100;
}

int Character::getDamage()
{
    return damage;
}

void Character::setDamage(int d)
{
    damage += d;
}

int Character::getPotion()
{
    return healthpotion;
}

void Character::setPotion(int p)
{
    healthpotion += p;
}

int Character::getMoney()
{
    return money;
}

void Character::setMoney(int m)
{
    money += m;
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
    if (enemy->getArmor() > 0)
    {
        int Armortemp = enemy->getArmor();
        enemy->setArmor(Armortemp - damage);

        if (enemy->getArmor() < 0)
        {
            int armortemp2 = enemy->getArmor();
            enemy->setArmor(0);

            int temp = enemy->getHealth();
            enemy->setHealth(temp + armortemp2);
        }
    }
    else
    {
        int temp = enemy->getHealth();
        enemy->setHealth(temp - damage);
    }
}

Character::~Character()
{
}
