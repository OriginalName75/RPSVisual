#pragma once
#include "Action.h"
class Block :
	public Action
{
public:
	Block(int timeInit, int timeAfter, int value, sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame>  actionFrames, std::vector<int> lostHitstun);
	Block();
	~Block();
	virtual void act(FutureAction* t, Player* cible, int cibleInt, bool block) const;
private:
	int updateOK(FutureAction* t, int player, TypeAttack  att) const;
	bool isInVect(ActionFrame a) const;
	void plus(FutureAction* t, int player) const;
};	

