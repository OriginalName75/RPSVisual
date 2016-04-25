#pragma once
#include <list>
#include "Player.h"
#include "ActionFrame.h"
#include "ModeJeu.h"
#include "ImagePerso.h"
#include "SoundCust.h"

class FutureAction
{
public:
	
	float speedFrame;
	int dec;
	Player* p1;
	Player* p2;
	ModeJeu mode;
	FutureAction(Player* p1, Player* p2, const SoundCust* zik, ModeJeu mode);
	FutureAction();	
	~FutureAction();
	int len;
	void print(sf::RenderWindow * app);
	std::list<ActionFrame> player1;
	std::list<ActionFrame> player2;
	void maj();
	void update();
	void startZik();
private:
	SoundCust* zik;
	sf::Sound sound;
	bool blocked;
	int j;
	sf::Clock clock;
	void auxupdate(std::list<ActionFrame> player1, Player* p1);
	void majAux(std::list<ActionFrame>* player, std::list<sf::Sprite>* sprites, Player* p);
	std::list<sf::Sprite> player1Sprites;
	std::list<sf::Sprite> player2Sprites;
	bool changed;
	void verifyActions();
	void auxverifyActions(std::list<ActionFrame> player1, std::list<ActionFrame> player2, Player* p1, Player* p2, int cibleIn1, int cibleIn2, bool* acted);
	ImagePerso one;
	ImagePerso two;
	ImagePerso tree;
	ImagePerso go;
	ImagePerso rytm;
	void printDec(sf::RenderWindow * app);
};

