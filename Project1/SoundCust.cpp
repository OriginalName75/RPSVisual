#include "SoundCust.h"



SoundCust::SoundCust(std::string str, int tempo):sf::SoundBuffer()
{
	this->tempo = tempo;
	if (!loadFromFile(str))

	{
		std::cout << "Erreur durant le chargement de la zik" << std::endl;


	}
}

SoundCust::SoundCust()
{
}


SoundCust::~SoundCust()
{
}
