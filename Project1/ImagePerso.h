#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class ImagePerso: public sf::Sprite
{
public:	

	void chargeImg(std::string linkImg);
	ImagePerso(std::string linkImg);
	ImagePerso(std::string linkImg, int x, int y);
	ImagePerso();
	~ImagePerso();
};

