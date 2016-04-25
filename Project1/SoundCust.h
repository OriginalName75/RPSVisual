#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class SoundCust: public sf::SoundBuffer
{
public:
	float tempo;
	std::string str;
	SoundCust(std::string str, float tempo);
	SoundCust();
	void load();
	~SoundCust();
};
