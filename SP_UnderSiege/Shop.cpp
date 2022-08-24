#include "Shop.h"
#include "Weapon.h"
#include <iostream>
#include <string>
#include "Armor.h"
#include "Elixir.h"
#include "Object.h"

Shop::Shop()
{
	x = 91;
	y = 25;
	accessory = new Object*[shopCapacity];
	accessory[0] = new Weapon;
	accessory[1] = new Armor;
	accessory[2] = new Elixir;
}

int Shop::getX()
{
	return x;
}

int Shop::getY()
{
	return y;
}

void Shop::printMenu(int &money)
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

Object* Shop::buy(int number, int &money)
{
	if (number-48 > shopCapacity || number-48 < 1)
	{
		buffer = "Item does not belong in the shop brotha";
		return nullptr;
	}
	buffer = "You bought "  + accessory[number - 49]->gettypeofObject() + "!";
	if (money < accessory[number - 49]->getPrice())
	{
		buffer = "You are broke! You cannot buy anymore things in the store anymore! ";
		return nullptr;
	}
	money -= accessory[number - 49]->getPrice();
	return accessory[number - 49];
}
