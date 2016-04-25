#pragma once
#include "FutureAction.h"
#include "ActData.h"
class Combat
{
public:
	FutureAction* t;
	Player* p1;
	Player* p2;
	sf::RenderWindow* app;
	Combat(Player* p1, Player* p2, FutureAction* t, sf::RenderWindow* app);
	~Combat();
	Combat();
	void update();
};

