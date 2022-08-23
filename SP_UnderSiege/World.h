#pragma once
#include "Character.h"
#include "Shop.h"
#include "Chest.h"

class World
{
public:
	World();

	char world[101][101];
	void updateWorldPositions(Character* player, Shop* shopLocate, Character* guard1, Character* guard2, Character* guard3, Chest* chest, Character* miniboss, Character* boss);
	void printWorld(Character* player, bool hostile);
	void printWorldMap(Character* player, Shop* shopLocate, bool hostile, Character* guard1, Character* guard2, Character* guard3, Chest* chest, Character* miniboss, Character* boss);
	

	~World();
};

