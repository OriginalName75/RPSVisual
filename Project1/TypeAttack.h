#pragma once
#include <SFML/Graphics.hpp> 
#include "Id.h"
class TypeAttack: 
	public Id
{
public:
	std::vector<const TypeAttack*> beats;
	sf::Keyboard::Key player1;
	sf::Keyboard::Key player2;
	
	TypeAttack(sf::Keyboard::Key player1, sf::Keyboard::Key player2, std::vector<const TypeAttack*> beats);
	TypeAttack();
	~TypeAttack();
};