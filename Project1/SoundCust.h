#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class SoundCust: public sf::SoundBuffer
{
public:
	int tempo;
	SoundCust(std::string str, int tempo);
	SoundCust();
	~SoundCust();
};

