#pragma once
#include "Player.h"
#include "FutureAction.h"
class IA:public Player
{
public:

	IA(const Heros hero, int isLeft);
	IA();
	~IA();
};

