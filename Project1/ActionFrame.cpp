#include "ActionFrame.h"
#include "ActData.h"

ActionFrame::ActionFrame()
{
}


ActionFrame::ActionFrame(std::string linkImg):ActionFrame::ActionFrame(linkImg, typeAttack::null, actionsSkin::normal)
{
	

}

ActionFrame::ActionFrame(std::string linkImg, TypeAttack typeAtt, const Id skinPerso):ActionFrame(linkImg, typeAtt)
{
	
	this->skinPerso = skinPerso;
	
	
}

ActionFrame::ActionFrame(std::string linkImg, const Id skinPerso): ActionFrame(linkImg, typeAttack::null, skinPerso)
{


}

ActionFrame::ActionFrame(std::string linkImg,  TypeAttack typeAtt):Id()
{

	img = new sf::Texture();
	this->typeAtt = typeAtt;
	if (!img->loadFromFile(linkImg)) // Si le chargement a échoué
	{
		std::cout << "Erreur durant le chargement de l'image : " + linkImg << std::endl;

	}
	img->setSmooth(true);
	
}


ActionFrame::~ActionFrame()
{
}
