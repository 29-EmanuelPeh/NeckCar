#include "World.h"
#include <iomanip>
#include <iostream>
#include <windows.h>


World::World()
{
	for (int x = 0; x < 31; x++)
	{
		for (int y = 0; y < 76; y++)
		{
			world[x][y] = '.';
		}
	}
}

void World::init(Character* guard1, Character* guard2, Character* guard3
	, Character* guard4, Character* guard5, Character* guard6
	, Character* guard7, Character* guard8, Character* guard9
	, Character* guard10, Character* guard11, Character* guard12
	, Character* guard13, Character* guard14, Character* guard15
	, Character* guard16, Character* guard17, Character* guard18
	, Character* guard19, Character* guard20, Character* guard21, Chest* chest, Chest* chest1, Chest* chest2)
{
	guard1->setX(3); guard1->setY(4); guard2->setX(13); guard2->setY(9); guard3->setX(16); guard3->setY(16);
	guard4->setX(27); guard4->setY(10); guard5->setX(27); guard5->setY(16); guard6->setX(1); guard6->setY(40);
	guard7->setX(5); guard7->setY(28); guard8->setX(17); guard8->setY(43); guard9->setX(19); guard9->setY(35);
	guard10->setX(23); guard10->setY(30); guard11->setX(27); guard11->setY(45); guard12->setX(1); guard12->setY(13);
	guard13->setX(1); guard13->setY(14); guard14->setX(1); guard14->setY(15); guard15->setX(1); guard15->setY(16);
	guard16->setX(1); guard16->setY(17); guard17->setX(1); guard17->setY(18); guard18->setX(1); guard18->setY(19);
	guard19->setX(1); guard19->setY(20); guard20->setX(1); guard20->setY(21); guard21->setX(1); guard21->setY(22);
	chest->setX(24); chest->setY(43);
	chest1->setX(6); chest1->setY(41);
	chest2->setX(4); chest2->setY(24);
}

void World::updateWorldPositions(Character* player, Shop* shopLocate
	, Character* guard1, Character* guard2, Character* guard3
	, Character* guard4, Character* guard5, Character* guard6
	, Character* guard7, Character* guard8, Character* guard9
	, Character* guard10, Character* guard11, Character* guard12
	, Character* guard13, Character* guard14, Character* guard15
	, Character* guard16, Character* guard17, Character* guard18
	, Character* guard19, Character* guard20, Character* guard21, Chest* chest, Chest* chest1, Chest* chest2, Character* miniboss, Character* boss)
{
	for (int x = 0; x < 31; x++)
	{
		for (int y = 0; y < 76; y++)
		{
			if (x == 0 || x == 30 || y == 0 || y == 75
			|| (y == 25 && (x != 14 && x != 15 && x != 16))
			|| y == 50 && (x != 14 && x != 15 && x != 16)
			|| x == 3 && (y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 4 && (y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 5 && (y == 30 || y == 31 || y == 44 || y == 45 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 6 && (y == 30 || y == 31 || y == 44 || y == 45 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 7 && (y == 30 || y == 31 || y == 44 || y == 45 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 8 && (y == 30 || y == 31 || y == 44 || y == 45 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 9 && (y == 30 || y == 31 || y == 44 || y == 45 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40)
			|| x == 12 && (y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 40 || y == 41 || y == 42 || y == 43 || y == 44 || y == 45)
			|| x == 13 && (y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 30 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 40 || y == 41 || y == 42 || y == 43 || y == 44 || y == 45)
			|| x == 14 && (y == 11 || y == 15)
			|| x == 15 && (y == 11 || y == 15)
			|| x == 16 && (y == 11 || y == 15)
			|| x == 17 && (y == 11 || y == 12 || y == 13 || y == 14 || y == 15)
			|| x == 4 && (y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22)
			|| x == 5 && (y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22)
			|| x == 6 && (y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22)
			|| x == 7 && (y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22)
			|| x == 8 && (y == 4 || y == 5 || y == 6 || y == 7 || y == 8 || y == 18 || y == 19 || y == 20 || y == 21 || y == 22)
			|| x == 22 && (y == 4 || y == 5 || y == 21 || y == 22 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 39 || y == 40 || y == 41 || y == 42 || y == 43 || y == 44)
			|| x == 23 && (y == 4 || y == 5 || y == 21 || y == 22 || y == 31 || y == 44)
			|| x == 24 && (y == 4 || y == 5 || y == 21 || y == 22 || y == 31 || y == 44)
			|| x == 25 && (y == 4 || y == 5 || y == 21 || y == 22 || y == 31 || y == 44)
			|| x == 26 && (y == 4 || y == 5 || y == 21 || y == 22 || y == 31 || y == 32 || y == 33 || y == 34 || y == 35 || y == 36 || y == 37 || y == 38 || y == 39 || y == 40 || y == 41 || y == 42 || y == 43 || y == 44))
			{
				world[x][y] = char(254);
			}
			else if ((x == 14 && (y == 12 || y == 13 || y == 14))
				  || (x == 15 && (y == 12 || y == 13 || y == 14))
				  || (x == 16 && (y == 12 || y == 13 || y == 14)))
			{
				world[x][y] = char(176);
			}
			else if (y == 50 && (x == 14 || x == 15 || x == 16) && miniboss != NULL)
			{
				world[x][y] = 'X';
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
			else if (guard4 != NULL && x == guard4->getX() && y == guard4->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard5 != NULL && x == guard5->getX() && y == guard5->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard6 != NULL && x == guard6->getX() && y == guard6->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard7 != NULL && x == guard7->getX() && y == guard7->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard8 != NULL && x == guard8->getX() && y == guard8->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard9 != NULL && x == guard9->getX() && y == guard9->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard10 != NULL && x == guard10->getX() && y == guard10->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard11 != NULL && x == guard11->getX() && y == guard11->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard12 != NULL && x == guard12->getX() && y == guard12->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard13 != NULL && x == guard13->getX() && y == guard13->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard14 != NULL && x == guard14->getX() && y == guard14->getY())
			{
				world[x][y] = 'G';
			}
			else if (guard15 != NULL && x == guard15->getX() && y == guard15->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard16 != NULL && x == guard16->getX() && y == guard16->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard17 != NULL && x == guard17->getX() && y == guard17->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard18 != NULL && x == guard18->getX() && y == guard18->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard19 != NULL && x == guard19->getX() && y == guard19->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard20 != NULL && x == guard20->getX() && y == guard20->getY())
			{
			world[x][y] = 'G';
			}
			else if (guard21 != NULL && x == guard21->getX() && y == guard21->getY())
			{
			world[x][y] = 'G';
			}
			else if (x == chest->getX() && y == chest->getY())
			{
				world[x][y] = chest->getchestIcon();
			}
			else if (x == chest1->getX() && y == chest1->getY())
			{
			world[x][y] = chest1->getchestIcon();
			}
			else if (x == chest2->getX() && y == chest2->getY())
			{
			world[x][y] = chest2->getchestIcon();
			}
			else if (miniboss != NULL && x == miniboss->getX() && y == miniboss->getY())
			{
				world[x][y] = 'M';
			}
			else if (boss != NULL && x == boss->getX() && y == boss->getY())
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

	int tempX = -10;
	int tempY = -10;

	for (size_t x = 0; x < 21; x++)
	{
		tempY = -10;

		for (size_t y = 0; y < 21; y++)
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
			else if (player != NULL && world[player->getX() + tempX][player->getY() + tempY] == 'M')
			{
				SetConsoleTextAttribute(h, 0x06);
			}
			else if (player != NULL && world[player->getX() + tempX][player->getY() + tempY] == char(225))
			{
				SetConsoleTextAttribute(h, 0x0C);
			}
			if (((player->getY() + tempY) >= 0) && 
				((player->getY() + tempY) <= 75) &&
				((player->getX() + tempX) >= 0) &&
				((player->getX() + tempX) <= 30))
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

void World::printWorldMap(bool hostile)
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

   	for (size_t x = 0; x < 31; x++)
	{
		// 2 Shop - 36
		for (size_t y = 0; y < 76; y++)
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

	std::cout << "                       CITY                                              MARKET                                             CASTLE" << std::endl;
}


World::~World()
{

}
