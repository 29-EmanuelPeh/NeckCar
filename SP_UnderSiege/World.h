#pragma once
#include "Character.h"
#include "Shop.h"
#include "Chest.h"

class World
{
public:
	World();

	char world[31][76];
	void init(Character* guard1, Character* guard2, Character* guard3
		, Character* guard4, Character* guard5, Character* guard6
		, Character* guard7, Character* guard8, Character* guard9
		, Character* guard10, Character* guard11, Character* guard12
		, Character* guard13, Character* guard14, Character* guard15
		, Character* guard16, Character* guard17, Character* guard18
		, Character* guard19, Character* guard20, Character* guard21, Chest* chest, Chest* chest1, Chest* chest2);
	void updateWorldPositions(Character* player, Shop* shopLocate
		, Character* guard1, Character* guard2, Character* guard3
		, Character* guard4, Character* guard5, Character* guard6
		, Character* guard7, Character* guard8, Character* guard9
		, Character* guard10, Character* guard11, Character* guard12
		, Character* guard13, Character* guard14, Character* guard15
		, Character* guard16, Character* guard17, Character* guard18
		, Character* guard19, Character* guard20, Character* guard21, Chest* chest , Chest* chest1, Chest* chest2, Character* miniboss, Character* boss);
	void printWorld(Character* player, bool hostile);
	void printWorldMap(bool hostile);
	

	~World();
};

