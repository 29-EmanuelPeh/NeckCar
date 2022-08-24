#include <iostream>
#include <string>
#include <windows.h>
#include "conio.h"
#include <stdlib.h>
#include "World.h"
#include "Shop.h"
#include "Guards.h"
#include "Chest.h"
#include "Boss.h"
#include "MiniBoss.h"

void slowPrint(std::string textToPrint, int speed)
{
	int x = 1;
	while (textToPrint[x] != '\0')
	{
		std::cout << textToPrint[x];
		Sleep(speed);
		x++;
	};

	std::cout << std::endl << std::endl;
}

int main()
{
	srand(static_cast <unsigned int> (time(0)));

	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 20;
	fontex.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	std::cout << " _    _           _              _____ _                 " << std::endl;
	std::cout << "| |  | |         | |            / ____(_)                " << std::endl;
	std::cout << "| |  | |_ __   __| | ___ _ __  | (___  _  ___  __ _  ___ " << std::endl;
	std::cout << "| |  | |  _  | / _ |/ _ |  __|  ___  || |/ _  / _  |/ _ |" << std::endl;
	std::cout << "| |__| | | | | (_| |  __/ |     ____) | ||  __|(_| |  __/" << std::endl;
	std::cout << "| ____/|_| |_| __,_| ___|_|    |_____/|_| ___| __, | ___|" << std::endl;
	std::cout << "                                               __/ |     " << std::endl;
	std::cout << "                                              |___/      " << std::endl;

	system("pause");

	World gameWorld;
	Character* hero = new Character;
	char dir = 0;

	Shop menu;
	bool shopOpen = false;

	Chest choo;
	Chest choo1;
	Chest choo2;
	
	Character* EnemyPtr[23] = { new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards
								,new Guards, new Guards , new Guards, new MiniBoss, new Boss };
	bool hostile = false;
	bool donezo = false;
	int nig2 = 0;
	int nig = 0;
	bool hasMoved = false;
	int BossSteps = 1;
	bool FinalBossCanMove = false;

	gameWorld.init(EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
			, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
			, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
			, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
			, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
			, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
			, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2);

	while (hero->getHealth() != 0)
	{
		do
		{
			system("CLS");
			gameWorld.updateWorldPositions(hero, &menu
				, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
				, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
				, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
				, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
				, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
				, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
				, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2, EnemyPtr[21], EnemyPtr[22]);

			if (!shopOpen)
			{
				gameWorld.printWorld(hero, hostile);
				hero->PrintStat();
				std::cout << "What do you want to do?(WASD to move, IJKL to attack, M for map, E to shop, Q to quit): " << std::endl;
			}
			else
			{
				menu.printMenu(hero->getMoney());
			}
			/*hero->printInventory();*/
			dir = _getch();
			std::cout << std::endl;
			if (shopOpen)
			{
				hero->addInventory(menu.buy(dir, hero->getMoney()));
			}

			//calling the function that the input has
			switch (dir)
			{
			case 'w':
				if (gameWorld.world[hero->getX() - 1][hero->getY()] == '.' && !shopOpen)
				{
					hero->move(dir);
					donezo = true;
				}
				else
				{
					donezo = false;
					continue;
				}

				break;
			case 's':
				if (gameWorld.world[hero->getX() + 1][hero->getY()] == '.' && !shopOpen)
				{
					hero->move(dir);
					donezo = true;
				}
				else
				{
					donezo = false;
					continue;
				}
				break;
			case 'a':
				if (gameWorld.world[hero->getX()][hero->getY() - 1] == '.' && !shopOpen)
				{
					hero->move(dir);
					donezo = true;
				}
				else
				{
					donezo = false;
					continue;
				}
				break;
			case 'd':
				if (gameWorld.world[hero->getX()][hero->getY() + 1] == '.' && !shopOpen)
				{
					hero->move(dir);
					donezo = true;
				}
				else
				{
					donezo = false;
					continue;
				}
				break;
			case 'i':
				for (int i = 0; i < 23; i++)
				{
					//check if any guards in the direction chosen are present
					if (EnemyPtr[i] != NULL)
					{
						if (hero->checkDir(dir, EnemyPtr[i]))
						{
							if (hostile)
							{
								hero->attack(EnemyPtr[i]);
							}
							donezo = true;
						}
						else
						{
							donezo = true;
							continue;
						}
					}
					else
					{
						donezo = true;
						continue;
					}
				}
				break;
			case 'k':
				for (int i = 0; i < 23; i++)
				{
					//check if any guards in the direction chosen are present
					if (EnemyPtr[i] != NULL)
					{
						if (hero->checkDir(dir, EnemyPtr[i]))
						{
							if (hostile)
							{
								hero->attack(EnemyPtr[i]);
							}
							donezo = true;
						}
						else
						{
							donezo = true;
							continue;
						}
					}
					else
					{
						donezo = true;
						continue;
					}
				}
				break;
			case 'j':
				for (int i = 0; i < 23; i++)
				{
					//check if any guards in the direction chosen are present
					if (EnemyPtr[i] != NULL)
					{
						if (hero->checkDir(dir, EnemyPtr[i]))
						{
							if (hostile)
							{
								hero->attack(EnemyPtr[i]);
							}
							donezo = true;
						}
						else
						{
							donezo = true;
							continue;
						}
					}
					else
					{
						donezo = true;
						continue;
					}
				}
				break;
			case 'l':
				for (int i = 0; i < 23; i++)
				{
					//check if any guards in the direction chosen are present
					if (EnemyPtr[i] != NULL)
					{
						if (hero->checkDir(dir, EnemyPtr[i]))
						{
							if (hostile)
							{
								hero->attack(EnemyPtr[i]);
							}
							donezo = true;
						}
						else
						{
							donezo = true;
							continue;
						}
					}
					else
					{
						donezo = true;
						continue;
					}
				}
				break;
			case 'h':
				hostile = true;
				donezo = false;
				break;
			case 'm':
				donezo = false;
				system("CLS");
				gameWorld.printWorldMap(hostile);
				std::cout << std::endl << std::endl << std::endl;
				system("pause");
				break;
			case 'e':
				if (hero->getX() == menu.getX() - 1 && hero->getY() == menu.getY() ||
					hero->getX() == menu.getX() && hero->getY() == menu.getY() + 1 ||
					hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY() + 1 ||
					hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY() - 1 ||
					hero->getX() == menu.getX() - 1 && hero->getY() == menu.getY() + 1 ||
					hero->getX() == menu.getX() - 1 && hero->getY() == menu.getY() - 1 ||
					hero->getX() == menu.getX() && hero->getY() == menu.getY() - 1 ||
					hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY()
					)
				{
					donezo = false;
					shopOpen = !shopOpen;
					menu.ResetShop();
				}
				 else if (hero->getX() == choo.getX() - 1 && hero->getY() == choo.getY() ||
						hero->getX() == choo.getX() && hero->getY() == choo.getY() + 1 ||
						hero->getX() == choo.getX() && hero->getY() == choo.getY() - 1 ||
						hero->getX() == choo.getX() + 1 && hero->getY() == choo.getY())
				{
					donezo = false;
					int monei = choo.open();
					hero->getMoney() += monei;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + "credits" << std::endl;
					system("pause");
				}
				 else if (hero->getX() == choo1.getX() - 1 && hero->getY() == choo1.getY() ||
					 hero->getX() == choo1.getX() && hero->getY() == choo1.getY() + 1 ||
					 hero->getX() == choo1.getX() && hero->getY() == choo1.getY() - 1 ||
					 hero->getX() == choo1.getX() + 1 && hero->getY() == choo1.getY())
				{
					donezo = false;
					int monei = choo1.open();
					hero->getMoney() += monei;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + "credits" << std::endl;
					system("pause");
				}
				 else if (hero->getX() == choo2.getX() - 1 && hero->getY() == choo2.getY() ||
					 hero->getX() == choo2.getX() && hero->getY() == choo2.getY() + 1 ||
					 hero->getX() == choo2.getX() && hero->getY() == choo2.getY() - 1 ||
					 hero->getX() == choo2.getX() + 1 && hero->getY() == choo2.getY())
				{
					donezo = false;
					int monei = choo2.open();
					hero->getMoney() += monei;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + "credits" << std::endl;
					system("pause");
				}
				 else
				{
					donezo = false;
				}
				break;
			case 'q':
				exit(0);
			default:
				donezo = false;
				break;
			}
		} while (!donezo);

			

		//checking enemies health
		for (int i = 0; i < 23; i++)
		{
			// if guard has not died and is lower than 0 in health
			if (EnemyPtr[i] != NULL && EnemyPtr[i]->getHealth() <= 0)
			{
				hero->getMoney() += static_cast<Guards*>(EnemyPtr[i])->getWorth();
				//DELETE guard
				delete EnemyPtr[i];
				EnemyPtr[i] = NULL;
			}
			// if guard has died
			else if (EnemyPtr[i] == NULL)
			{
				continue;
			}
			// if guard is alive
			else
				continue;
		}

		char temp[4] = { 'i','k' ,'j' ,'l' };

		for (int i = 0; i < 23; i++)
		{
			if (EnemyPtr[i] != NULL)
			{
				// checking if player is near each guard
				for (size_t p = 0; p < 4; p++)
				{
					EnemyPtr[i]->canAttack = EnemyPtr[i]->checkDir(temp[p], hero);

					if (EnemyPtr[i]->canAttack == true)
						break;
				}

				// if hostile is false, they will not attack
				if (hostile == false)
				{
					EnemyPtr[i]->canAttack = false;
				}

				if (EnemyPtr[i]->canAttack == true)
				{
					// if player is 1 square away, attack is called
					EnemyPtr[i]->attack(hero);
				}
				else
				{
					// check if its guards or bosses
					if (i < 21)
					{
						// if no player near to attack, try to move
						do
						{
							//randomizing whether to move X or Y
							nig = rand() % 2;

							// X chosen
							if (nig == 0)
							{
								// randomizes to move +1 or -1
								do
								{
									nig2 = (rand() % 3) - 1;

								} while (nig2 == 0);

								//updates the world positions
								gameWorld.updateWorldPositions(hero, &menu
									, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
									, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
									, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
									, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
									, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
									, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
									, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2, EnemyPtr[21], EnemyPtr[22]);

								// checking if the spot is empty
								if (gameWorld.world[EnemyPtr[i]->getX() + nig2][EnemyPtr[i]->getY()] != '.')
								{
									hasMoved = false;
									continue;
								}
								else
								{
									if (nig2 == 1)
									{
										EnemyPtr[i]->move('s');
										hasMoved = true;
									}
									else
									{
										EnemyPtr[i]->move('w');
										hasMoved = true;
									}
								}
							}
							// Y chosen
							else
							{
								// randomizes to move +1 or -1
								do
								{
									nig2 = (rand() % 3) - 1;

								} while (nig2 == 0);

								//updates world positions
								gameWorld.updateWorldPositions(hero, &menu
									, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
									, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
									, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
									, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
									, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
									, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
									, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2, EnemyPtr[21], EnemyPtr[22]);

								if (gameWorld.world[EnemyPtr[i]->getX()][EnemyPtr[i]->getY() + nig2] != '.')
								{
									hasMoved = false;
									continue;
								}
								else
								{
									if (nig2 == 1)
									{
										EnemyPtr[i]->move('d');
										hasMoved = true;
									}
									else
									{
										EnemyPtr[i]->move('a');
										hasMoved = true;
									}
								}
							}
						} while (hasMoved == false);
					}
					// if its bosses
					else
					{
						if (BossSteps % 2 == 0 && hostile)
						{
							//updates the world positions
							gameWorld.updateWorldPositions(hero, &menu
								, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
								, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
								, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
								, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
								, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
								, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
								, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2, EnemyPtr[21], EnemyPtr[22]);

							bool Moved = false;
							
							if (i == 22)
							{
								// final boss can only move when player activated final event
								if (!FinalBossCanMove)
								{
									BossSteps++;
									continue;
								}
							}

							do
							{
								if ((EnemyPtr[i]->getX() < hero->getX()) && (gameWorld.world[EnemyPtr[i]->getX() + 1][EnemyPtr[i]->getY()] == '.'))
								{
									EnemyPtr[i]->move('s');
									Moved = true;
									if (i == 22)
									{
										BossSteps++;
									}
								}
								else if ((EnemyPtr[i]->getX() > hero->getX()) && (gameWorld.world[EnemyPtr[i]->getX() - 1][EnemyPtr[i]->getY()] == '.'))
								{
									EnemyPtr[i]->move('w');
									Moved = true;
									if (i == 22)
									{
										BossSteps++;
									}
								}
								else if ((EnemyPtr[i]->getY() > hero->getY()) && (gameWorld.world[EnemyPtr[i]->getX()][EnemyPtr[i]->getY() - 1] == '.'))
								{
									EnemyPtr[i]->move('a');
									Moved = true;
									if (i == 22)
									{
										BossSteps++;
									}
								}
								else if ((EnemyPtr[i]->getY() < hero->getY()) && (gameWorld.world[EnemyPtr[i]->getX()][EnemyPtr[i]->getY() + 1] == '.'))
								{
									EnemyPtr[i]->move('d');
									Moved = true;
									if (i == 22)
									{
										BossSteps++;
									}
								}
								else
								{
									Moved = true;
									if (i == 22)
									{
										BossSteps++;
									}
								}
							} while (!Moved);
						}
						else
						{
							if (i == 22)
							{
								BossSteps++;
							}
						}
					}
				}
			}
		}
	}

	system("CLS");
	gameWorld.updateWorldPositions(hero, &menu
		, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2]
		, EnemyPtr[3], EnemyPtr[4], EnemyPtr[5]
		, EnemyPtr[6], EnemyPtr[7], EnemyPtr[8]
		, EnemyPtr[9], EnemyPtr[10], EnemyPtr[11]
		, EnemyPtr[12], EnemyPtr[13], EnemyPtr[14]
		, EnemyPtr[15], EnemyPtr[16], EnemyPtr[17]
		, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], &choo, &choo1, &choo2, EnemyPtr[21], EnemyPtr[22]);
	gameWorld.printWorld(hero, hostile);
	hero->PrintStat();

	// LOSE AND WIN CONDITIONS
	//LOSE
	if (hero->getHealth() == 0)
	{
		std::cout << std::endl << std::endl << "YOU LOSE" << std::endl << std::endl;
		Sleep(1000);
		system("pause");
	}

	return 0;
}