#include "SoundCust.h"



SoundCust::SoundCust(std::string str, float tempo):sf::SoundBuffer()
{
	this->tempo = tempo;
	this->str = str;
}

SoundCust::SoundCust()
{
}

void SoundCust::load()
{
	if (!loadFromFile(str))

	{
		std::cout << "Erreur durant le chargement de la zik : "+str << std::endl;


	}
}


SoundCust::~SoundCust()
{
}
