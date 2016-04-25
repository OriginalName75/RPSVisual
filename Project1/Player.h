#pragma once
#include "Heros.h"
#include "SkinLoaded.h"


class Player :
	public Id
{
public:
	int blockCD;
	bool blockPress;
	bool error;
	int isComboted;
	bool beingCombo;
	int hp;
	virtual bool isH();
	Player(const Heros hero, int isLeft);
	Player();
	~Player();
	void print(sf::RenderWindow * app);
	void maj(ActionFrame act);
	void majLife();
	void majTurn();
	
private:
	sf::RectangleShape life;
	sf::RectangleShape mana;
	SkinLoaded skin;
	int isLeft;
	

};

