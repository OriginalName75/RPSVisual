#include "SkinLoaded.h"



SkinLoaded::SkinLoaded(Skin skin, int isLeft)
{
	this->isLeft = isLeft;
	actionsframes = skin.actionsframes;

	for each (sf::Texture* txt in skin.textures)
	{
		
		
		sf::Sprite* spri = new sf::Sprite();
		spri->setTexture(*txt);
		setImage(spri);
		sprites.push_back(spri);

		
	}
	if (!isLeft) {
	
		turnImages();
	}
	draw = sprites.front();
	

}

SkinLoaded::SkinLoaded()
{
}


SkinLoaded::~SkinLoaded()
{
}

void SkinLoaded::turnImages()
{
	for each (sf::Sprite* spr in sprites)
	{
		
		turnImage(spr);
	}
	

}

void SkinLoaded::print(sf::RenderWindow * app)
{
	app->draw(*draw);
}

void SkinLoaded::maj(ActionFrame act)
{

	std::list<Id>::iterator list_iter = actionsframes.begin();
	for each (sf::Sprite* s in sprites)
	{
	
		
		if (act.skinPerso==*list_iter) {
			
			draw = s;
			break;
		}

		list_iter++;
		
		
	}
}

void SkinLoaded::turnImage(sf::Sprite* spri)
{
	spri->setOrigin({ spri->getLocalBounds().width, 0 });
	spri->setScale({ -1, 1 });
}

void SkinLoaded::setImage(sf::Sprite* spri)
{
	int y = 200;

	if (isLeft) {
		spri->setPosition(50, y);
	}
	else {
		spri->setPosition(600, y);
	}
	
}

