#include "ImagePerso.h"

using namespace std;
using namespace sf;

ImagePerso::ImagePerso(std::string linkImg)
{
	chargeImg(linkImg);
}

ImagePerso::ImagePerso()
{
}


ImagePerso::~ImagePerso()
{
}

void ImagePerso::chargeImg(std::string linkImg)
{

	Image img;
	if (!img.loadFromFile(linkImg)) // Si le chargement a échoué
	{
		cout << "Erreur durant le chargement de l'image : " + linkImg << endl;

	}

	Texture *tx = new Texture();
	if (!(*tx).loadFromImage(img)) // Si le chargement a échoué
	{
		cout << "Erreur durant le chargement de la texture de l'image " + linkImg << endl;

	}
	else {

		setTexture(*tx);

	}
}