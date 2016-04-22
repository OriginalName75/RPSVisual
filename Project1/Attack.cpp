#include "Attack.h"
#include "ActData.h"




Attack::Attack(int timeInit, int timeAfter, int value, sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame> actionFrames, std::vector<int> lostHitstun, int blockValue, int blockstun )
	:Action(timeInit, timeAfter, value, player1, player2, actionFrames, lostHitstun)
{
	this->blockstun = blockstun;
	isAtt = true;
	this->blockValue = blockValue;
	
}



Attack::~Attack()
{
}

Attack::Attack()
{
}

void Attack::act(FutureAction * t, Player* cible, int cibleInt, bool block) const
{
	int degs = value;
	if (!block) {
		degs = value;
		
		
	}
	else {
		degs = blockValue;
	
	}
	
	if (cibleInt == 1) {
		if (t->p2->error && t->p1->beingCombo) {
			
			std::cout << " Erreur de latt" << std::endl;
			degs = degs / 2;
		}

		t->p2->error = false;
	}
	else {

		if (t->p1->error && t->p2->beingCombo) {
			std::cout << " Erreur de latt" << std::endl;
			degs = degs / 2;
		}
		t->p1->error = false;
	}
	cible->hp = cible->hp - degs;
	std::cout << std::to_string(degs) + " enleve" << std::endl;
	cible->majLife();
	int maxxx;
	if (cibleInt == 1) {
		
		t->player1.clear();
	}
	else {
		t->player2.clear();
	}
	std::vector<int>::const_iterator acti = lostHitstun.begin();

	for (int i = 0; i < cible->isComboted; i++)
	{
		if (i<lostHitstun.size()-1) {
			acti++;
		}
		
	}
	
	
	
	
	int max = *acti +1;
	if (block) {
		max = blockstun+1;
	}
	std::cout << "stun pendant " + std::to_string(max) + " tours" << std::endl;
	if (cibleInt == 1) {
		if (max>0) {
			t->p1->beingCombo = true;
		}
	}
	else {
		if (max>0) {
			t->p2->beingCombo = true;
		}
	}
	for (int i = 0; i < max; i++) {
		if (cibleInt == 1) {
			t->player1.push_back(actionFrames::stun);
		}
		else {
			t->player2.push_back(actionFrames::stun);
		}
	}
	cible->isComboted = cible->isComboted + 1;
	t->maj();
}

int Attack::updateOK(FutureAction * t, int player, TypeAttack att) const
{
	
	std::list<ActionFrame>*  list;
	if (player==1) {
		list = &t->player1;
	}
	else {
		list = &t->player2;
	}
	
	if (list->empty() || list->front() == actionFrames::idle) {
		
		list->clear();
		
		for (int i = 0; i < timeInit;i++) {
			list->push_back(actionFrames::preparing);
		}
		
		for each (ActionFrame action in actionFrames)
		{
			
			
			if (action.typeAtt == att) {
				
				list->push_back(action);
				std::cout << "Vous avez attaqué" << std::endl;
				
				break;
			}
		}
		for (int i = 0; i < timeAfter; i++) {
			list->push_back(actionFrames::endlag);
		}
		return true;

	}
	else if (!list->empty() && !(list->front() == actionFrames::idle || list->front() == actionFrames::preparing)) {
		if (player == 1) {
			t->p1->error = true;
		}
		else {
			t->p2->error = true;
		}
	}
	return false;
}
