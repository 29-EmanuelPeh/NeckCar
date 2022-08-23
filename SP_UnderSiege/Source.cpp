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
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 30;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

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

	Chest choo(5,5);
	
	Character* EnemyPtr[5] = { new Guards, new Guards , new Guards, new MiniBoss, new Boss };
	bool hostile = false;
	bool donezo = false;
	int nig2 = 0;
	int nig = 0;
	bool hasMoved = false;

	while (hero->getHealth() != 0)
	{
		do
		{
			system("CLS");
			gameWorld.updateWorldPositions(hero, &menu, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2], &choo, EnemyPtr[3], EnemyPtr[4]);

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
				if (gameWorld.world[hero->getX() - 1][hero->getY()] == '.')
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
				if (gameWorld.world[hero->getX() + 1][hero->getY()] == '.')
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
				if (gameWorld.world[hero->getX()][hero->getY() - 1] == '.')
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
				if (gameWorld.world[hero->getX()][hero->getY() + 1] == '.')
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
				for (int i = 0; i < 5; i++)
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
							continue;
						}
					}
					else
					{
						continue;
					}
				}
				break;
			case 'k':
				for (int i = 0; i < 5; i++)
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
							continue;
						}
					}
					else
					{
						continue;
					}
				}
				break;
			case 'j':
				for (int i = 0; i < 5; i++)
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
							continue;
						}
					}
					else
					{
						continue;
					}
				}
				break;
			case 'l':
				for (int i = 0; i < 5; i++)
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
							continue;
						}
					}
					else
					{
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
				gameWorld.printWorldMap(hero, &menu, hostile, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2], &choo, EnemyPtr[3], EnemyPtr[4]);
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
					hero->getX() == choo.getX() + 1 && hero->getY() == choo.getY() + 1 ||
					hero->getX() == choo.getX() + 1 && hero->getY() == choo.getY() - 1 ||
					hero->getX() == choo.getX() - 1 && hero->getY() == choo.getY() + 1 ||
					hero->getX() == choo.getX() - 1 && hero->getY() == choo.getY() - 1 ||
					hero->getX() == choo.getX() && hero->getY() == choo.getY() - 1 ||
					hero->getX() == choo.getX() + 1 && hero->getY() == choo.getY()
					)
				{
					donezo = false;
					int monei = choo.open();
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
		for (int i = 0; i < 5; i++)
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

		for (int i = 0; i < 5; i++)
		{
			if (EnemyPtr[i] != NULL)
			{
				// checking if player is near each guard
				for (size_t p = 0; p < 4; p++)
				{
					EnemyPtr[i]->canAttack = EnemyPtr[i]->checkDir(temp[p], hero);

					if (EnemyPtr[i]->canAttack == true)
						break;
					else
						continue;
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
							gameWorld.updateWorldPositions(hero, &menu, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2], &choo, EnemyPtr[3], EnemyPtr[4]);

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
							gameWorld.updateWorldPositions(hero, &menu, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2], &choo, EnemyPtr[3], EnemyPtr[4]);

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
			}
		}
	}

	gameWorld.updateWorldPositions(hero, &menu, EnemyPtr[0], EnemyPtr[1], EnemyPtr[2], &choo, EnemyPtr[3], EnemyPtr[4]);

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