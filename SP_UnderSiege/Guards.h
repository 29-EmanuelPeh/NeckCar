#pragma once
#include "Character.h"
class Guards : public Character
{
	int worth = rand()% 5 + 1;
public:
	Guards();
	int getWorth();


	~Guards();
};

