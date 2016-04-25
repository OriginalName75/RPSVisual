#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human(const Heros hero, int isLeft);
	Human();
	~Human();
	bool isH();
	
};

