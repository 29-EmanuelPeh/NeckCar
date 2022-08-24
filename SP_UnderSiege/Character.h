#pragma once
#include "Object.h"
class Character
{
protected:
	int health;
	int damage;
	int armor;
	int healthpotion;
	int range;
	int x;
	int y;
	int money;
	static const int inventorySize = 3;
	Object* inventory[inventorySize];
	int currentCapacity = 0;
public:
	Character();

	void PrintStat(void);
	bool canAttack;
	int getX();
	void setX(int px);
	int getY();
	void setY(int py);
	int getHealth();
	void setHealth(int h);
	int getDamage();
	int getRange();
	void move(char dir);
	bool checkDir(char dir, Character* enemy);
	void attack(Character* enemy);
	void addInventory(Object* object);
	void printInventory();
	int getMoney();
	void setMoney(int money);
	~Character();
};