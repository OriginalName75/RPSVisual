#include "Combat.h"



Combat::Combat()
{
}

void Combat::update()
{
	for each (const Action* action in actions::listAction) {
		action->update(t);
	}
	t->update();
	t->print(app);
	p1->print(app);
	p2->print(app);
}


Combat::Combat(Player* p1, Player* p2, FutureAction* t, sf::RenderWindow* app)
{
	this->p1 = p1;
	this->p2 = p2;
	this->t = t;
	this->app = app;
}

Combat::~Combat()
{
}
