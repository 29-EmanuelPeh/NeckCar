#pragma once
#include <iostream>
#include "Character.h"
class Shop
{
private:
	char shopIcon;
	int x;
	int y;
	std::string buffer = "Welcome to URAYA. What would you like to purchase? 1 - Weapon |  2 - Knights Armor | 3 - Elixir";
public:
	Shop();
	void slowPrint(std::string text, int speed);
	int getX();
	int getY();
	void printMenu(int money);
	void ResetShop();
	void buy(int number , Character* player);
	

};

