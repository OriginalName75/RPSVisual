#include "Player.h"



bool Player::isH()
{
	return false;
}

Player::Player(const Heros hero, int isLeft)
{
	error = false;
	blockCD = 0;
	blockPress = false;
	isComboted = 0;
	hp = 20;
	beingCombo = false;
	life = sf::RectangleShape();
	life.setFillColor(sf::Color(0, 250, 0));
	mana = sf::RectangleShape();
	mana.setFillColor(sf::Color(250, 0, 0));
	majLife();
	
	if (isLeft) {
		life.setPosition({50,170});
		mana.setPosition({ 50,165 });
	}
	else {
		life.setPosition({600,170 });
		mana.setPosition({ 600,165 });
	}
	skin = SkinLoaded(hero.skin, isLeft);

	this->isLeft = isLeft;
	if (!isLeft) {
		skin.turnImages();
	}
}

Player::Player()
{
	
}




Player::~Player()
{
}

void Player::print(sf::RenderWindow * app)
{
	app->draw(life);
	app->draw(mana);
	skin.print(app);
}

void Player::maj(ActionFrame act)
{
	
	skin.maj(act);
}

void Player::majLife()
{
	life.setSize(sf::Vector2f(hp * 3, 2));
	mana.setSize(sf::Vector2f(blockCD, 2));
}

void Player::majTurn()
{
	if (blockCD>0) {
		blockCD = blockCD - 1;
	}
	
}



