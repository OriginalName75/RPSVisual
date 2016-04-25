#include <cstdlib>
#include <SFML/Graphics.hpp> 
#include <iostream>
#include "Human.h"
#include "IA.h"
#include "playData.h"
#include "Combat.h"
#include "Musics.h"
using namespace sf;
using namespace std;


int main()
{
	
	bool pause;
	pause = true;
	bool clicked = false;

	srand(time(NULL));

	// Create a window with the same pixel depth as the desktop
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow app(sf::VideoMode(800, 600, desktop.bitsPerPixel), "Ma premiere fenetre SFML ! ");
	app.setFramerateLimit(60);
	app.setVerticalSyncEnabled(true);

	Player* p1 = new Human(heros::warrior, true);
	Player* p2 = new IA(heros::traveller, false);
	FutureAction t = FutureAction(p1, p2, musics::defa,1);
	
	Combat c = Combat(p1,p2, &t, &app);
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
	
		c.update();
		
		app.display();
	}
	return EXIT_SUCCESS;
}