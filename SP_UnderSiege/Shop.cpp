#include "Shop.h"
#include <iostream>
#include <string>

Shop::Shop()
{
	x = 24;
	y = 32;
}

int Shop::getX()
{
	return x;
}

int Shop::getY()
{
	return y;
}

void Shop::printMenu(int money)
{
	std::cout << "*************************************************************************************" << std::endl;
	std::cout << "*" << "                                        Shop                                      " << " * " << std::endl;
	std::cout << "*" << "                                        ----                                      " << " * " << std::endl;
	std::cout << "*" << "     (1) Weapon:  40 credits                                                      " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "     (2) Knights Armor: 50 credits                                                " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "     (3) Elixir:  10 credits                                                      " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;;
	std::cout << "*" << "    Amount of money: " << money << "                                               "<< " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*************************************************************************************" << std::endl;

	for (int j = 0; j < buffer.size(); j++)
	{
		for (int i = 0; i <= 10000000; i++);
		std::cout << buffer[j];
	}
	std::cout << std::endl;
}

void Shop::ResetShop()
{
	buffer = "Welcome to URAYA. What would you like to purchase? 1 - Weapon |  2 - Knights Armor | 3 - Elixir";
}

void Shop::buy(int number, Character* player)
{
	switch (number)
	{
	case 49:
		if (player->getMoney() >= 40)
		{
			player->setDamage(10);
			player->setMoney(-40);

			buffer = "You bought Weapon!";

			ResetShop();
		}
		else
		{
			buffer = "You are broke! You cannot buy anymore things in the store anymore! ||  1 - Weapon |  2 - Knights Armor | 3 - Elixir ";
		}
		break;
	case 50:
		if (player->getMoney() >= 50)
		{
			player->setArmor(50);
			player->setMoney(-50);

			buffer = "You bought Armor!";

			ResetShop();
		}
		else
		{
			buffer = "You are broke! You cannot buy anymore things in the store anymore! ||  1 - Weapon |  2 - Knights Armor | 3 - Elixir ";
		}
		break;
	case 51:
		if (player->getMoney() >= 10)
		{
			player->setPotion(1);
			player->setMoney(-10);

			buffer = "You bought Health Potion!";

			ResetShop();
		}
		else
		{
			buffer = "You are broke! You cannot buy anymore things in the store anymore! ||  1 - Weapon |  2 - Knights Armor | 3 - Elixir ";
		}
		break;
	default:
		buffer = "Not an item! ||  1 - Weapon |  2 - Knights Armor | 3 - Elixir ";
		break;
	}
}
