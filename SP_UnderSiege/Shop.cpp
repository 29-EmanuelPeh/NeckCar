#include "Shop.h"
#include <iostream>
#include <Windows.h>
#include <string>

Shop::Shop()
{
	x = 24;
	y = 32;
	shopIcon = 'C';
}

int Shop::getX()
{
	return x;
}

int Shop::getY()
{
	return y;
}

void Shop::slowPrint(std::string textToPrint, int speed)
{
	int x = 0;
	while (textToPrint[x] != '\0')
	{
		std::cout << textToPrint[x];
		Sleep(speed);
		x++;
	};

	std::cout << std::endl << std::endl;
}

void Shop::printMenu(int money)
{
	std::cout << "*************************************************************************************" << std::endl;
	std::cout << "*" << "                                        Shop                                      " << " * " << std::endl;
	std::cout << "*" << "                                        ----                                      " << " * " << std::endl;
	std::cout << "*" << "     (1) Weapon:  30 credits                                                      " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "     (2) Knights Armor: 30 credits                                                " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "     (3) Elixir:  10 credits                                                      " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;;
	std::cout << "*" << "    Amount of money: " << money << "                                              " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*" << "                                                                                  " << " * " << std::endl;
	std::cout << "*************************************************************************************" << std::endl;

	slowPrint(buffer, 1);
}

void Shop::ResetShop()
{
	buffer = "Welcome to URAYA. What would you like to purchase? 1 - Weapon |  2 - Knights Armor | 3 - Elixir | E to get out";
}

void Shop::buy(int number, Character* player)
{
	switch (number)
	{
	case 49:
		if (player->getMoney() >= 30)
		{
			player->setDamage(10);
			player->setMoney(-30);

			std::cout << "You bought Weapon!" << std::endl;
			system("pause");

			ResetShop();
		}
		else
		{
			std::cout << "You are broke!" << std::endl;
			system("pause");

			ResetShop();
		}
		break;
	case 50:
		if (player->getMoney() >= 30)
		{
			player->setArmor(50);
			player->setMoney(-30);

			std::cout << "You bought Armor!" << std::endl;
			system("pause");

			ResetShop();
		}
		else
		{
			std::cout << "You are broke!" << std::endl;
			system("pause");

			ResetShop();
		}
		break;
	case 51:
		if (player->getMoney() >= 10)
		{
			player->setPotion(1);
			player->setMoney(-10);

			std::cout << "You bought Health Potion!" << std::endl;
			system("pause");

			ResetShop();
		}
		else
		{
			std::cout << "You are broke!" << std::endl;
			system("pause");

			ResetShop();
		}
		break;
	case 'e':
		break;
	default:
		std::cout << "Not an item!" << std::endl;
		system("pause");

		ResetShop();
		break;
	}
}
