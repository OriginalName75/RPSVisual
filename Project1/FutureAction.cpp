#include "FutureAction.h"
#include "ActData.h"


using namespace sf;
using namespace std;
FutureAction::FutureAction(Player * p1, Player * p2, const SoundCust* zik, ModeJeu mode):FutureAction()
{
	
	this->p1 = p1;
	this->p2 = p2;
	this->mode = mode;
	this->zik = new SoundCust(*zik);
	
	this->speedFrame = this->zik->tempo;

	sound = Sound();
	sound.setLoop(true);
	this->zik->load();
	sound.setBuffer(*this->zik);
	
}
FutureAction::FutureAction()
{
	dec = 4;
	float x = 50;
	float y = 80;
	len = 25;
	one = ImagePerso("img/decompte/1.png", 400 - 23, 0);
	two = ImagePerso("img/decompte/2.png", 400 - 23, 0);
	tree = ImagePerso("img/decompte/3.png", 400 - 23, 0);
	go = ImagePerso("img/decompte/go.png", 400 - 23, 0);
	rytm = ImagePerso("img/decompte/rytm.png",x+5 , 30);
	
	for (int i = 0; i < len; i++)
	{
		 
		
		Sprite* s = new Sprite();
		s->setTexture(*actionFrames::idle.img);
		s->setPosition(28*(len - i) + x, y);
		player1Sprites.push_front(*s);
		Sprite* s2 = new Sprite();
		s2->setTexture(*actionFrames::idle.img);
		s2->setPosition(28* (len - i) + x, 28 + y);
		player2Sprites.push_front(*s2);
	}
	
	
}


FutureAction::~FutureAction()
{
}

void FutureAction::print(sf::RenderWindow * app)
{
	for each (Sprite s in player1Sprites)
	{
		app->draw(s);
	}
	for each (Sprite s in player2Sprites)
	{
		app->draw(s);
	}
	printDec(app);
	if (clock.getElapsedTime().asSeconds() < speedFrame / 6) {
		app->draw(rytm);
	}
}

void FutureAction::maj()
{

	majAux(&player1, &player1Sprites, p1);
	majAux(&player2, &player2Sprites, p2);
	
}

void FutureAction::update()
{
	if (clock.getElapsedTime().asSeconds() >= speedFrame) {

		clock.restart();
		if (dec <2) {
			if (dec==1) {
				dec--;
			}
			changed = false;
			blocked = false;
			p1->majTurn();
			p2->majTurn();

			if (!player1.empty()) {

				std::list<ActionFrame>::iterator list_iter = player1.begin();
				for each (ActionFrame actF in actionFrames::listProtect)
				{
					if (*list_iter == actF) {
						blocked = true;
					}
				}
				if (!blocked || player1.size() < len - 1) {
					player1.pop_front();
					changed = true;
				}

			}
			blocked = false;
			if (!player2.empty()) {

				std::list<ActionFrame>::iterator list_iter = player2.begin();
				for each (ActionFrame actF in actionFrames::listProtect)
				{
					if (*list_iter == actF) {
						blocked = true;
					}
				}

				if (!blocked || player2.size() < len - 1) {

					player2.pop_front();
					changed = true;
				}
			}


			if (changed) {
				std::cout << "" << std::endl;

				maj();
				verifyActions();
			}
			else {
				p1->majLife();
				p2->majLife();
			}

			auxupdate(player1, p1);
			auxupdate(player2, p2);
		}
		else {
			dec--;
		}
	}
}

void FutureAction::startZik()
{
	sound.play();
	clock.restart();

}

void FutureAction::auxupdate(std::list<ActionFrame> player1, Player* p1)
{
	if (!player1.empty()) {
		if (player1.front() == actionFrames::idle) {
			p1->beingCombo = false;
		}
		if (!(player1.front() == actionFrames::stun)) {
			p1->isComboted = 0;

		}
	
		
		
	}
	else {
		p1->beingCombo = false;
		p1->isComboted = 0;
		
	}
}

void FutureAction::majAux(std::list<ActionFrame>* player, std::list<sf::Sprite>* sprites, Player* p)
{
	
	std::list<sf::Sprite>::iterator list_iter = sprites->begin();
	j = 0;
	for each (ActionFrame actionf in *player)
	{
		if (j<len) {
			if (list_iter != sprites->end()) {
				list_iter->setTexture(*actionf.img);


			}
			list_iter++;
		}
		j++;
		
	}
	while (list_iter != sprites->end()) {
		list_iter->setTexture(*actionFrames::idle.img);
		list_iter++;
	}
	if (!player->empty()) {
		std::list<ActionFrame>::iterator iter = player->begin();

		p->maj(*iter);
	}
	else {
		
		p->maj(actionFrames::idle);
	}

	
}

void FutureAction::verifyActions()
{
	bool acted = false;
	if (dec<2) {
		auxverifyActions(player1, player2, p1, p2, 1, 2, &acted);
		auxverifyActions(player2, player1, p2, p1, 2, 1, &acted);
	}
	
}

void FutureAction::auxverifyActions(std::list<ActionFrame> player1, std::list<ActionFrame> player2, Player* p1, Player* p2, int cibleIn1, int cibleIn2, bool* acted)
{
	

	if (!player1.empty()) {

		std::list<ActionFrame>::iterator act = player1.begin();
		if (!(*act == actionFrames::idle) && !(*act == actionFrames::preparing)) {

			bool found = false;
			for each (const Action* acti in actions::listAction)
			{

				for each (ActionFrame  a in acti->actionFrames)
				{

					if (a == *act) {

						found = true;

						break;

					}
				}
				if (found) {
					if (acti->isAtt) {

						if (player2.empty()) {
							acti->act(this, p2, cibleIn2, false);

						}
						else {

							std::list<ActionFrame>::iterator actio = player2.begin();
							if (*actio == actionFrames::idle || *actio == actionFrames::stun || *actio == actionFrames::preparing) {
								*acted = true;
								acti->act(this, p2, cibleIn2, false);
							}
							else {
								if (!*acted) {


									bool findu = false;
									for each (const Action* a in actions::listAction)
									{
										for each (ActionFrame actionfra in a->actionFrames)
										{
											if (actionfra == *actio) {

												*acted = true;


												if (act->typeAtt == actio->typeAtt) {
													if (a->isAtt) {
														acti->act(this, p2, cibleIn2, false);
														a->act(this, p1, cibleIn1, false);
													}
													else {
														acti->act(this, p2, cibleIn2, true);
													}

												}
												else {
													bool sup = false;
													for each (const TypeAttack* ty in act->typeAtt.beats)
													{
														if (ty->id == actio->typeAtt.id) {
															sup = true;
															break;
														}
													}

													if (sup) {

														acti->act(this, p2, cibleIn2, false);// les deux ca c'est la meme

													}
													else {



														a->act(this, p1, cibleIn1, false);

													}

												}




												findu = true;
												break;
											}
										}
										if (findu) {
											break;
										}
									}
								}
							}
						}
					}
				
					break;
				}
			}

		}
	}
}

void FutureAction::printDec(sf::RenderWindow * app)
{
	if (dec>0) {
		if (dec==4) {
			app->draw(tree);
		}
		else if (dec == 3) {
			app->draw(two);
		}
		else if (dec == 2) {
			app->draw(one);
		}
		else {
			app->draw(go);
		}
	}
}


