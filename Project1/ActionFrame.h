#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "TypeAttack.h"


class ActionFrame :	
	public Id
{
public:
	Id skinPerso;
	TypeAttack typeAtt;
	sf::Texture* img;
	ActionFrame(std::string linkImg, TypeAttack typeAtt, const Id skinPerso);
	ActionFrame(std::string linkImg, const Id skinPerso);
	ActionFrame(std::string linkImg, TypeAttack typeAtt);
	ActionFrame(std::string linkImg);
	~ActionFrame();
	ActionFrame();
	
};

