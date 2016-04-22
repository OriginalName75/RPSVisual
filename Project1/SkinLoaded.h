#pragma once
#include <SFML/Graphics.hpp> 
#include "Skin.h"
#include <list>
class SkinLoaded
{
public:
	std::vector<sf::Sprite*> sprites;
	std::list<Id> actionsframes;
	sf::Sprite* draw;
	SkinLoaded(Skin skin, int isLeft);
	SkinLoaded();
	~SkinLoaded();
	void turnImages();
	void print(sf::RenderWindow * app);
	void maj(ActionFrame act);
private:
	int isLeft;
	void turnImage(sf::Sprite* spri);
	void setImage(sf::Sprite* spri);
};

