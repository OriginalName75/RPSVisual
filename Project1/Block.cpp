#include "Block.h"
#include "ActData.h"
#include <algorithm>  



Block::Block(int timeInit, int timeAfter, int value, sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<ActionFrame> actionFrames, std::vector<int> lostHitstun) : Action(timeInit, timeAfter, value, player1, player2, actionFrames, lostHitstun)
{

}

Block::Block()
{
}


Block::~Block()
{
}

void Block::act(FutureAction * t, Player * cible, int cibleInt, bool block) const
{
	cible->hp = cible->hp - value;
	std::cout << std::to_string(value) + " enleve sur block" << std::endl;
	if (cibleInt == 1) {
		t->player1.clear();
		for (int i = 0; i < lostHitstun.front()+1; i++)
		{
			t->player1.push_back(actionFrames::stun);
		}
		t->p1->beingCombo = true;
		t->player2.clear();
		t->player2.push_back(actionFrames::preparing);
		t->player2.push_back(actionFrames::preparing);
	}
	else {
		t->p2->beingCombo = true;
		t->player2.clear();
		for (int i = 0; i < lostHitstun.front()+1; i++)
		{
			t->player2.push_back(actionFrames::stun);
		}
		t->player1.clear();
		t->player1.push_back(actionFrames::preparing);
		t->player1.push_back(actionFrames::preparing);
	}
	t->maj();
}

int Block::updateOK(FutureAction * t, int player, TypeAttack att) const
{
	
	std::list<ActionFrame>*  list;
	bool blockPress;
	if (player == 1) {
		blockPress=t->p1->blockPress;
		t->p1->blockPress=true;
		list = &t->player1;
	}
	else {
		blockPress= t->p2->blockPress;
		t->p2->blockPress = true;
		list = &t->player2;
	}

	if (list->empty() || list->front() == actionFrames::idle) {

		list->clear();
		list->push_back(actionFrames::preparing);
		
		for each (ActionFrame action in actionFrames)
		{


			if (action.typeAtt == att) {

				for (int i = 0; i < t->len; i++) {
					list->push_back(action);
				}

				std::cout << "Vous avez parré" << std::endl;
				return true;
			
			}
		}

	}
	
	else if (!list->empty() && isInVect(list->front()) && !blockPress) {
		list->clear();
		
		for each (ActionFrame action in actionFrames)
		{


			if (action.typeAtt == att) {

				
				list->push_back(action);
				

				std::cout << "Cancel" << std::endl;
				break;

			}
		}
		list->push_back(actionFrames::preparing);
		return true;
		
	}
	return false;
	
}
bool Block::isInVect(ActionFrame a) const
{

	for each (ActionFrame ac in actionFrames)
	{
		if (ac == a) {
			return true;
		}
	}
	return false;
}

void Block::plus(FutureAction* t, int player) const
{
	if (player==1) {
		t->p1->blockPress = false;
	}
	else {
		t->p2->blockPress = false;
	}
	
}




