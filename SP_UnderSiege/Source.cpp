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
#include "Dialogue.h"

void ClearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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
	system("CLS");

	Dialogue consoletext;
	bool dialogueHappening = false;
	int dialogueNum = 0;

	//background story
	std::cout << "   / |                                                       /|" << std::endl;
	std::cout << "  |  |                                                      | |" << std::endl;
	std::cout << "/---- |                                                   /----|" << std::endl;
	std::cout << "[______]                                                 [______]" << std::endl;
	std::cout << " |    |         _____                        _____        |    |" << std::endl;
	std::cout << "|[]  |        [     ]                      [     ]        |  []|" << std::endl;
	std::cout << "|    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |" << std::endl;
	std::cout << " |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |" << std::endl;
	std::cout << " |             |     |/'    ____..____    ' |     |             |" << std::endl;
	std::cout << "  |  []        |     |    /'    ||    '    |     |        []  /" << std::endl;
	std::cout << "   |      []   |     |   |o     ||     o|   |     |  []       |" << std::endl;
	std::cout << "   |           |  _  |   |     _||_     |   |  _  |           |" << std::endl;
	std::cout << "   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |" << std::endl;
	std::cout << "   |           |     |   |     (||)     |   |     |           |" << std::endl;
	std::cout << "   |           |     |   |      ||      |   |     |           |" << std::endl;
	std::cout << " /''           |     |   |o     ||     o|   |     |           '' " << std::endl;
	std::cout << "[_____________[_______]--'------''------'--[_______]_____________]" << std::endl << std::endl << std::endl << std::endl;

	consoletext.intro();

	World gameWorld;
	Character* hero = new Character;
	char dir = 0;

	Shop menu;
	bool shopOpen = false;

	Chest* choo = new Chest;
	Chest* choo1 = new Chest;
	Chest* choo2 = new Chest;
	Chest* choo3 = new Chest;
	
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
			, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], choo, choo1, choo2, choo3);

	// intro hint dialogue
	dialogueHappening = true;
	dialogueNum = 1;

	bool HavenotTalkedToCastleGuards = true;

	bool HavenoTalkedToSuperior = true;

	bool SuperiorNotDefeated = true;
	int tempcounter = 0;

	bool HaveNotTalkedToBoss = true;
	int tempcounter2 = 0;

	while (hero->getHealth() != 0 && EnemyPtr[22] != NULL)
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
				, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], choo, choo1, choo2, choo3, EnemyPtr[21], EnemyPtr[22]);

			//check if first time talk to guards have not happened
			if (HavenotTalkedToCastleGuards == true && ((hero->getX() == 14 || hero->getX() == 15 || hero->getX() == 16) && hero->getY() == 49))
			{
				HavenotTalkedToCastleGuards = false;
				dialogueHappening = true;
				dialogueNum = 2;
			}

			//check if first time talk to superior
			if (HavenoTalkedToSuperior == true && HavenotTalkedToCastleGuards == false && (hero->getX() == 21 && (hero->getY() == 1 || hero->getY() == 2 || hero->getY() == 3
				|| hero->getY() == 4 || hero->getY() == 5 || hero->getY() == 6
				|| hero->getY() == 7 || hero->getY() == 8 || hero->getY() == 9
				|| hero->getY() == 10 || hero->getY() == 11 || hero->getY() == 12
				|| hero->getY() == 13 || hero->getY() == 14 || hero->getY() == 15
				|| hero->getY() == 16 || hero->getY() == 17 || hero->getY() == 18
				|| hero->getY() == 19 || hero->getY() == 20 || hero->getY() == 21
				|| hero->getY() == 22 || hero->getY() == 23 || hero->getY() == 24)))
			{
				HavenoTalkedToSuperior = false;
				dialogueHappening = true;
				dialogueNum = 3;
				hostile = true;
			}

			//if try walk out of city while still fighting miniboss
			if (HavenoTalkedToSuperior == false && HavenotTalkedToCastleGuards == false && SuperiorNotDefeated == true && ((hero->getX() == 14 || hero->getX() == 15 || hero->getX() == 16) && hero->getY() == 25))
			{
				dialogueHappening = true;
				dialogueNum = 7;
				hero->setY(24);
			}

			//if superior dead
			if (EnemyPtr[21] == NULL && tempcounter == 0)
			{
				SuperiorNotDefeated = false;
				tempcounter++;
				dialogueHappening = true;
				dialogueNum = 4;
			}

			//check if player talk to superior when havent talk to guards
			if (HavenotTalkedToCastleGuards == true && (hero->getX() == 21 && (hero->getY() == 1 || hero->getY() == 2 || hero->getY() == 3
				|| hero->getY() == 4 || hero->getY() == 5 || hero->getY() == 6
				|| hero->getY() == 7 || hero->getY() == 8 || hero->getY() == 9
				|| hero->getY() == 10 || hero->getY() == 11 || hero->getY() == 12
				|| hero->getY() == 13 || hero->getY() == 14 || hero->getY() == 15
				|| hero->getY() == 16 || hero->getY() == 17 || hero->getY() == 18
				|| hero->getY() == 19 || hero->getY() == 20 || hero->getY() == 21
				|| hero->getY() == 22 || hero->getY() == 23 || hero->getY() == 24)))
			{
				dialogueHappening = true;
				dialogueNum = 8;
				hero->setX(20);
			}

			//check if player first time entered boss room
			if (HaveNotTalkedToBoss == true && hero->getY() == 63 && (hero->getX() == 14 || hero->getX() == 15 || hero->getX() == 16))
			{
				HaveNotTalkedToBoss = false;
				dialogueHappening = true;
				dialogueNum = 5;
				FinalBossCanMove = true;
			}

			// check if player tries to get out while fighting boss
			if (HaveNotTalkedToBoss == false && hero->getY() == 62 && (hero->getX() == 14 || hero->getX() == 15 || hero->getX() == 16))
			{
				dialogueHappening = true;
				dialogueNum = 7;
				hero->setY(63);
			}

			if (!shopOpen)
			{
				gameWorld.printWorld(hero, hostile);

				// check if dialogue is triggered
				if (!dialogueHappening)
				{
					hero->PrintStat();
					std::cout << "What do you want to do?(WASD to move, IJKL to attack, H to heal, M for map, E to interact): " << std::endl;
				}
				else
				{
					// type of dialogue to play
					switch (dialogueNum)
					{
					case 1:
						consoletext.introHint();
						break;
					case 2:
						consoletext.CastleGuardTalk();
						break;
					case 3:
						consoletext.MeetSuperiorFirstTime();
						break;
					case 4:
						consoletext.BeatSuperiorFirstTime();
						break;
					case 5:
						consoletext.MeetBoss();
						break;
					case 6:
						consoletext.DefeatBoss();
						break;
					case 7:
						consoletext.LeaveBossFight();
						break;
					case 8:
						consoletext.TalkToSuperiorBeforeCastleGuards();
						break;
					}

					dialogueHappening = false;
					continue;
				}
			}
			else
			{
				menu.printMenu(hero->getMoney());
			}
			dir = _getch();
			std::cout << std::endl;
			if (shopOpen)
			{
				menu.buy(dir, hero);
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
				if (hero->getHealth() < 100)
				{
					if (hero->getPotion() > 0)
					{
						hero->setPotion(-1);

						int playertemp = hero->getHealth();
						hero->setHealth(playertemp + 35);
					}
				}
				donezo = true;
				break;
			case 'p':
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
					hero->getX() == menu.getX() && hero->getY() == menu.getY() - 1 ||
					hero->getX() == menu.getX() + 1 && hero->getY() == menu.getY())
				{
					donezo = false;
					shopOpen = !shopOpen;
					menu.ResetShop();
				}
				 else if (choo != NULL && (hero->getX() == choo->getX() - 1 && hero->getY() == choo->getY() ||
						hero->getX() == choo->getX() && hero->getY() == choo->getY() + 1 ||
						hero->getX() == choo->getX() && hero->getY() == choo->getY() - 1 ||
						hero->getX() == choo->getX() + 1 && hero->getY() == choo->getY()))
				{
					donezo = false;
					int monei = choo->open();
					hero->setMoney(monei);
					delete choo;
					choo = NULL;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + " credits" << std::endl;
					system("pause");
				}
				 else if (choo1 != NULL && (hero->getX() == choo1->getX() - 1 && hero->getY() == choo1->getY() ||
					 hero->getX() == choo1->getX() && hero->getY() == choo1->getY() + 1 ||
					 hero->getX() == choo1->getX() && hero->getY() == choo1->getY() - 1 ||
					 hero->getX() == choo1->getX() + 1 && hero->getY() == choo1->getY()))
				{
					donezo = false;
					int monei = choo1->open();
					hero->setMoney(monei);
					delete choo1;
					choo1 = NULL;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + " credits" << std::endl;
					system("pause");
				}
				 else if (choo2 != NULL && (hero->getX() == choo2->getX() - 1 && hero->getY() == choo2->getY() ||
					 hero->getX() == choo2->getX() && hero->getY() == choo2->getY() + 1 ||
					 hero->getX() == choo2->getX() && hero->getY() == choo2->getY() - 1 ||
					 hero->getX() == choo2->getX() + 1 && hero->getY() == choo2->getY()))
				{
					donezo = false;
					int monei = choo2->open();
					hero->setMoney(monei);
					delete choo2;
					choo2 = NULL;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + " credits" << std::endl;
					system("pause");
				}
				 else if (choo3 != NULL && (hero->getX() == choo3->getX() - 1 && hero->getY() == choo3->getY() ||
					 hero->getX() == choo3->getX() && hero->getY() == choo3->getY() + 1 ||
					 hero->getX() == choo3->getX() && hero->getY() == choo3->getY() - 1 ||
					 hero->getX() == choo3->getX() + 1 && hero->getY() == choo3->getY()))
				{
					donezo = false;
					int monei = choo3->open();
					hero->setMoney(monei);
					delete choo3;
					choo3 = NULL;
					std::cout << "You opened a choo chest! You have earned " + std::to_string(monei) + " credits" << std::endl;
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
				if (i < 21)
				{
					hero->setMoney((rand() % 5) + 1);
				}
				else
				{
					hero->setMoney(50);
				}

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
									, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], choo, choo1, choo2, choo3, EnemyPtr[21], EnemyPtr[22]);

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
									, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], choo, choo1, choo2, choo3, EnemyPtr[21], EnemyPtr[22]);

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
								, EnemyPtr[18], EnemyPtr[19], EnemyPtr[20], choo, choo1, choo2, choo3, EnemyPtr[21], EnemyPtr[22]);

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

	// LOSE AND WIN CONDITIONS
	//LOSE
	if (hero->getHealth() == 0)
	{
		delete hero;

		//delete remaining enemies if have
		for (size_t i = 0; i < 23; i++)
		{
			if (EnemyPtr[i] != NULL)
			{
				delete EnemyPtr[i];
				EnemyPtr[i] = NULL;
			}
		}

		//delete remaining chests if have
		if (choo != NULL)
		{
			delete choo;
			choo = NULL;
		}
		if (choo1 != NULL)
		{
			delete choo1;
			choo1 = NULL;
		}
		if (choo2 != NULL)
		{
			delete choo2;
			choo2 = NULL;
		}
		if (choo3 != NULL)
		{
			delete choo3;
			choo3 = NULL;
		}

		consoletext.Dead();
	}
	//WIN
	else if (EnemyPtr[22] == NULL)
	{
		delete hero;

		//delete remaining enemies if have
		for (size_t i = 0; i < 23; i++)
		{
			if (EnemyPtr[i] != NULL)
			{
				delete EnemyPtr[i];
				EnemyPtr[i] = NULL;
			}
		}

		//delete remaining chests if have
		if (choo != NULL)
		{
			delete choo;
			choo = NULL;
		}
		if (choo1 != NULL)
		{
			delete choo1;
			choo1 = NULL;
		}
		if (choo2 != NULL)
		{
			delete choo2;
			choo2 = NULL;
		}
		if (choo3 != NULL)
		{
			delete choo3;
			choo3 = NULL;
		}

		consoletext.DefeatBoss();
	}

	return 0;
}