#include "Skin.h"
#include "ActData.h"
using namespace std;


Skin::Skin(string start)
{
	
	string stri;
	

	for each (Id ids in actionsSkin::actions)
	{
		
		stri = start + ids.name;
		sf::Texture* txt = new sf::Texture();
	
		if (!txt->loadFromFile(stri)) // Si le chargement a échoué
		{
			std::cout << "Erreur durant le chargement de l'image : " + stri << std::endl;

		}
		txt->setSmooth(true);
		textures.push_back(txt);
		actionsframes.push_back(ids);
	}
	
}

Skin::Skin()
{
}


Skin::~Skin()
{
}

