#pragma once
class Boss
{
protected:
	int Health;
	int Damage;
	int x;
	int y;
public:
	Boss();

	int getX();
	int getY();
	void attack(int worldX, int worldY);
};

