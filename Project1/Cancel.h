#pragma once
#include "Action.h"
class Cancel :
	public Action
{
public:
	Cancel(sf::Keyboard::Key player1, sf::Keyboard::Key player2);
	Cancel();
	~Cancel();
private:
	void keyOnly(FutureAction* t, int player) const;
};

