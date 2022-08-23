﻿#include "World.h"
#include <iomanip>
#include <iostream>
#include <windows.h>


World::World()
{
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			world[x][y] = '.';
		}
	}
}

void World::updateWorldPositions(Character* player, Shop* shopLocate, Character* guard1, Character* guard2, Character* guard3, Chest* chest)
{
	/*if (guard1->getHealth() <= 0)
	{
		kill(guard1);
	}
	if (guard2->getHealth() <= 0)
	{
		kill(guard2);
	}
	if (guard3->getHealth() <= 0)
	{
		kill(guard3);
	}*/
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			if (x == 0 || x == 100 || y == 0 || y == 100 || x == 50 && (y == 40 || y == 41 || y == 42 || y == 43))
			{
				world[x][y] = char(254);
			}
			else if (x == player->getX() && y == player->getY())
			{
				world[x][y] = 2;
			}
			else if (x == shopLocate->getX() && y == shopLocate->getY())
			{
				world[x][y] = char(36);
			}
			else if (guard1 != NULL && x == guard1->getX() && y == guard1->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard2 != NULL && x == guard2->getX() && y == guard2->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard3 != NULL && x == guard3->getX() && y == guard3->getY())
			{
				world[x][y] = 'G';
			}
			else if (x == chest->getX() && y == chest->getY())
			{
				world[x][y] = chest->getchestIcon();
			}
			else 
			{
				world[x][y] = '.';
			}
		}
	}
}

void World::printWorld(Character* player, bool hostile)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int tempX = -10;
	int tempY = -10;

	for (size_t x = 0; x < 21; x++)
	{
		tempY = -10;

		for (size_t y = 0; y < 21; y++)
		{
			if (world[player->getX() + tempX][player->getY() + tempY] == char(254))
			{
				SetConsoleTextAttribute(h, 0x05);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == 2)
			{
				SetConsoleTextAttribute(h, 0x02);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == char(36))
			{
				SetConsoleTextAttribute(h, 0x01);
			}
			else if (player != NULL && world[player->getX() + tempX][player->getY() + tempY] == 'G')
			{
				if (hostile)
				{
					SetConsoleTextAttribute(h, 0x04);
				}
				else
				{
					SetConsoleTextAttribute(h, 0x08);
				}
			}
			if (((player->getY() + tempY) >= 0) && 
				((player->getY() + tempY) <= 100) &&
				((player->getX() + tempX) >= 0) &&
				((player->getX() + tempX) <= 100))
			{
				std::cout << world[player->getX() + tempX][player->getY() + tempY];
			}
			else
			{
				std::cout << ' ';
			}

			std::cout << ' ';

			SetConsoleTextAttribute(h, 0x0f);
			tempY++;
		}
		std::cout << std::endl;
		tempX++;
	}
	std::cout << std::endl;
}

void World::printWorldMap(Character* player, Shop* shopLocate, bool hostile, Character* guard1, Character* guard2, Character* guard3)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Legend:" << "                     |" << std::endl;
	std::cout << char(2) << "-> Player(YOU)" << "             |" << std::endl;
	std::cout << "G" << "->Guards" << "                   |" << std::endl;
	std::cout << char(36) << "->Shop" << "                     |" << std::endl;
	std::cout << "C" << "->Chest" << "                    |" << std::endl; 
	std::cout << "M" << "->Miniboss" << "                 |" << std::endl;
	std::cout << "B" << "->Boss" << "                     |" << std::endl; 
	std::cout << "-----------------------------" << std::endl;
   	for (size_t x = 0; x < 101; x++)
	{
		// 2 Shop - 36
		for (size_t y = 0; y < 101; y++)
		{
			if (world[x][y] == char(254))
			{
				SetConsoleTextAttribute(h, 0x05);
			}
			else if (world[x][y] == 2)
			{
				SetConsoleTextAttribute(h, 0x02);
			}
			else if (world[x][y] == char(36))
			{
				SetConsoleTextAttribute(h, 0x01);
			}
			else if (world[x][y] == 'G')
			{
				if (hostile)
				{
					SetConsoleTextAttribute(h, 0x04);
				}
				else
				{
					SetConsoleTextAttribute(h, 0x08);
				}
			}
			std::cout << world[x][y];
			SetConsoleTextAttribute(h, 0x0f);
		}
		std::cout << std::endl;
	}
}


World::~World()
{

}
