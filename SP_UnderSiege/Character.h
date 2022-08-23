#pragma once
#include "Object.h"
class Character
{
protected:
	int health;
	int damage;
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
	void setX();
	int getY();
	void setY();
	int getHealth();
	void setHealth(int h);
	int getDamage();
	int getRange();
	void move(char dir);
	bool checkDir(char dir, Character* enemy);
	void attack(Character* enemy);
	void addInventory(Object* object);
	void printInventory();
	int& getMoney();

	~Character();
};