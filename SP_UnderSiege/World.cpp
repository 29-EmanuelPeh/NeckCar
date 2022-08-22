#include "World.h"
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

void World::updateWorldPositions(Character* player, Shop* shopLocate, Character* guard1, Character* guard2, Character* guard3)
{
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			if (x == 0 || x == 100 || y == 0 || y == 100 || x == 50 && (y == 40 || y == 41 || y == 42 || y == 43))
			{
				world[x][y] = '+';
			}
			else if (x == player->getX() && y == player->getY())
			{
				world[x][y] = 'P';
			}
			else if (x == shopLocate->getX() && y == shopLocate->getY())
			{
				world[x][y] = 'S';
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
			else 
			{
				world[x][y] = '.';
			}
		}
	}
}

void World::printWorld(Character* player)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int tempX = -10;
	int tempY = -10;

	for (size_t x = 0; x < 21; x++)
	{
		tempY = -10;

		for (size_t y = 0; y < 21; y++)
		{
			if (world[player->getX() + tempX][player->getY() + tempY] == '+')
			{
				SetConsoleTextAttribute(h, 0x05);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == 'P')
			{
				SetConsoleTextAttribute(h, 0x02);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == 'S')
			{
				SetConsoleTextAttribute(h, 0x01);
			}
			else if (player != NULL && world[player->getX() + tempX][player->getY() + tempY] == 'G')
			{
				SetConsoleTextAttribute(h, 0x04);
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
}

void World::printWorldMap(Character* player, Shop* shopLocate, Character* guard1, Character* guard2, Character* guard3)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t x = 0; x < 101; x++)
	{
		for (size_t y = 0; y < 101; y++)
		{
			if (world[x][y] == '+')
			{
				SetConsoleTextAttribute(h, 0x05);
			}
			else if (world[x][y] == 'P')
			{
				SetConsoleTextAttribute(h, 0x02);
			}
			else if (world[x][y] == 'S')
			{
				SetConsoleTextAttribute(h, 0x01);
			}
			else if (world[x][y] == 'G')
			{
				SetConsoleTextAttribute(h, 0x04);
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
