#pragma once
#include "Action.h"
#include "TypeAttack.h"
#include <vector>
class Attack :
	public Action
{
public:
	int blockstun;
	int blockValue;
	
	
	Attack(int timeInit, int timeAfter, int value, sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame> actionFrames,  std::vector<int> lostHitstun, int blockValue, int blockstun);
	~Attack();
	Attack();
	void act(FutureAction* t, Player* cible, int cibleInt, bool block) const;
private:
	int updateOK(FutureAction* t, int player, TypeAttack att) const;

};

