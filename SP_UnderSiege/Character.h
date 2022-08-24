#pragma once

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
	int getArmor();
	void setArmor(int a);
	int getDamage();
	void setDamage(int d);
	int getPotion();
	void setPotion(int p);
	void move(char dir);
	bool checkDir(char dir, Character* enemy);
	void attack(Character* enemy);
	int getMoney();
	void setMoney(int money);
	~Character();
};