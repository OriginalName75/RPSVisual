#include "Action.h"
#include "ActData.h"
Action::Action(sf::Keyboard::Key player1, sf::Keyboard::Key player2)
{
	this->player1 = player1;
	this->player2 = player2;
}
Action::Action(int timeInit, int timeAfter, int value,  sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame> actionFrames, std::vector<int> lostHitstun) :Id()
{
	isAtt = false;
	this->timeInit = timeInit;
	this->timeAfter = timeAfter;
	this->value = value;
	this->lostHitstun = lostHitstun;
	this->player1 = player1;
	this->player2 = player2;
	this->actionFrames = actionFrames;

}


Action::Action()
{
}

void Action::update(FutureAction * t) const
{
	
	int finish=true;
	for each (TypeAttack ty in typeAttack::listtypeAttack)
	{
		
		if (updateAux(t,ty)) {
			break;
		}
	}
}

void Action::act(FutureAction * t, Player* cible, int cibleInt, bool block) const
{
	
}

int Action::updateAux(FutureAction * t, TypeAttack ta) const
{
	if (sf::Keyboard::isKeyPressed(player1))
	{
		keyOnly(t, 1);
	}
	else {
		plus(t, 1);
	}
	if (sf::Keyboard::isKeyPressed(player2))
	{
		keyOnly(t, 2);
	}
	else {
		plus(t, 2);
	}
	
	
	if (sf::Keyboard::isKeyPressed(player1) && sf::Keyboard::isKeyPressed(ta.player1))
	{
		
		
		if (updateOK(t, 1, ta)) {
			
			t->maj();
		}
		return true;
	}
	else {
		
		if (sf::Keyboard::isKeyPressed(player2) && sf::Keyboard::isKeyPressed(ta.player2))
		{
			if (updateOK(t, 2, ta)) {
				t->maj();
			}
			return true;
		}
		else {
			
			return false;
		}
	}

}

int Action::updateOK(FutureAction * t, int player, TypeAttack att) const
{
	
	return 0;
}

void Action::plus(FutureAction * t, int player) const
{
}

void Action::keyOnly(FutureAction * t, int player) const
{
}





Action::~Action()
{
}
