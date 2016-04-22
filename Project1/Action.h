#pragma once
#include <SFML/Graphics.hpp> 
#include "Id.h"
#include "FutureAction.h"
#include "TypeAttack.h"
class Action:
	public Id
{
public:
	bool isAtt;
	
	std::vector<ActionFrame> actionFrames;
	int timeInit;
	int timeAfter;
	std::vector<int> lostHitstun;
	int value;
	sf::Keyboard::Key player1;
	sf::Keyboard::Key player2;
	Action(sf::Keyboard::Key player1, sf::Keyboard::Key player2);
	Action(int timeInit, int timeAfter, int value, sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame> actionFrames, std::vector<int> lostHitstun);
	Action();
	void update(FutureAction* t) const;
	virtual void act(FutureAction* t, Player* cible, int cibleInt, bool block) const;
	~Action();
	
private:
	int updateAux(FutureAction* t, TypeAttack ta) const;
	virtual int updateOK(FutureAction* t, int player, TypeAttack att) const;
	virtual void plus(FutureAction* t, int player) const;
	virtual void keyOnly(FutureAction* t, int player) const;
};

