#include "TypeAttack.h"



TypeAttack::TypeAttack(sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<const TypeAttack*> beats)
{
	this->beats = beats;
	this->player1 = player1;
	this->player2 = player2;
}

TypeAttack::TypeAttack()
{
}


TypeAttack::~TypeAttack()
{
}
