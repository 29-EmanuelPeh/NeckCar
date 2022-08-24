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

void World::updateWorldPositions(Character* player, Shop* shopLocate, Character* guard1, Character* guard2, Character* guard3, Chest* chest, Character* miniboss, Character* boss)
{
	for (int x = 0; x < 101; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			if (x == 0 || x == 100 || y == 0 || y == 100
				|| (x == 5 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 6 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 7 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 8 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 9 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 40 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 41 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 42 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 43 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 44 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16 || y == 17 || y == 18 || y == 19 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 22 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 23 && (y == 22 || y == 23 || y == 24 || y == 25 || y == 26 || y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 24 && (y == 21 || y == 27 || y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 25 && (y == 21 || y == 27 || y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 26 && (y == 21 || y == 27 || y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 27 && (y == 22 || y == 23 || y == 24 || y == 25 || y == 26 || y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 28 && (y == 9 || y == 10 || y == 11 || y == 12 || y == 37 || y == 38 || y == 39 || y == 40))
				|| (x == 11 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 12 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 13 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 14 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 15 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 36 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 37 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 38 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 39 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (x == 40 && (y == 82 || y == 81 || y == 80 || y == 79 || y == 78 || y == 77 || y == 76 || y == 61 || y == 60 || y == 59 || y == 58 || y == 57 || y == 56 || y == 55))
				|| (y == 51 && (x != 24 && x != 25 && x != 26 && x != 74 && x != 75 && x != 76))
				|| (x == 51 && (y != 24 && y != 25 && y != 26)))
			{
				world[x][y] = char(254);
			}
			else if ((x == 24 && (y == 22 || y == 23 || y == 24 || y == 25 || y == 26))
				  || (x == 25 && (y == 22 || y == 23 || y == 24 || y == 25 || y == 26))
				  || (x == 26 && (y == 22 || y == 23 || y == 24 || y == 25 || y == 26))
				  || (x == 1 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 2 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 3 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 4 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 5 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 6 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 7 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 8 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 9 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 10 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 11 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 12 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 13 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 14 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 15 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 16 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 17 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 18 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 19 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 20 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 21 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 22 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 23 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 24 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 25 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 26 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 27 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 28 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 29 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 30 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 31 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 32 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 33 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 34 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 35 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 36 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 37 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 38 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 39 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99 || y == 94 || y == 93 || y == 92 || y == 91 || y == 90 || y == 89 || y == 88 || y == 87))
				|| (x == 40 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 41 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 42 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 43 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 44 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 45 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 46 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 47 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 48 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 49 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99))
				|| (x == 50 && (y == 95 || y == 96 || y == 97 || y == 98 || y == 99)))
			{
				world[x][y] = char(176);
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
			else if (x == miniboss->getX() && y == miniboss->getY())
			{
				world[x][y] = 'M';
			}
			else if (x == boss->getX() && y == boss->getY())
			{
				world[x][y] = char(225);
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

	int tempX = -15;
	int tempY = -15;

	for (size_t x = 0; x < 36; x++)
	{
		tempY = -15;

		for (size_t y = 0; y < 36; y++)
		{
			if (world[player->getX() + tempX][player->getY() + tempY] == char(254))
			{
				SetConsoleTextAttribute(h, 0x08);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == char(176))
			{
				SetConsoleTextAttribute(h, 0x0B);
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
			else if (world[player->getX() + tempX][player->getY() + tempY] == 'C')
			{
				SetConsoleTextAttribute(h, 0x0E);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == 'M')
			{
				SetConsoleTextAttribute(h, 0x06);
			}
			else if (world[player->getX() + tempX][player->getY() + tempY] == char(225))
			{
				SetConsoleTextAttribute(h, 0x0C);
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

void World::printWorldMap(Character* player, Shop* shopLocate, bool hostile, Character* guard1, Character* guard2, Character* guard3, Chest* chest, Character* miniboss, Character* boss)
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
				SetConsoleTextAttribute(h, 0x08);
			}
			else if (world[x][y] == char(176))
			{
				SetConsoleTextAttribute(h, 0x0B);
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
			else if (world[x][y] == 'C')
			{
				SetConsoleTextAttribute(h, 0x0E);
			}
			else if (world[x][y] == 'M')
			{
				SetConsoleTextAttribute(h, 0x06);
			}
			else if (world[x][y] == char(225))
			{
				SetConsoleTextAttribute(h, 0x0C);
			}
			std::cout << world[x][y] << ' ';
			SetConsoleTextAttribute(h, 0x0f);
		}
		std::cout << std::endl;
	}
}


World::~World()
{

}
