#include <cstdlib>
#include <SFML/Graphics.hpp> 
#include <iostream>
#include "Action.h"
#include "Human.h"
#include "FutureAction.h"
#include "ActData.h"
#include "playData.h"
#include "ActData.h"
#include "Musics.h"
using namespace sf;
using namespace std;


int main()
{
	Clock clock;
	bool pause;
	pause = true;
	bool clicked = false;

	srand(time(NULL));

	// Create a window with the same pixel depth as the desktop
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow app(sf::VideoMode(800, 600, desktop.bitsPerPixel), "Ma premiere fenetre SFML ! ");
	app.setFramerateLimit(60);
	app.setVerticalSyncEnabled(true);

	Player p1 = Human(heros::warrior, true);
	Player p2 = Human(heros::traveller, false);
	FutureAction t = FutureAction(&p1, &p2, musics::defa,1);
	t.startZik();

	while (app.isOpen())
	{
		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}

		app.clear();
	
		for each (const Action* action in actions::listAction) {
			action->update(&t);
		}
		t.update();
		t.print(&app);
		p1.print(&app);
		p2.print(&app);
		
		app.display();
	}
	return EXIT_SUCCESS;
}