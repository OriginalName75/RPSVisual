#pragma once
#include <SFML/Graphics.hpp> 
#include <string>
#include <iostream>
#include "Id.h"
#include <list>
#include "ActionFrame.h"

class Skin: public Id
{
public:
	std::vector<sf::Texture*> textures;
	std::list<Id> actionsframes;
	Skin(std::string start);
	Skin();
	~Skin();

};

