#pragma once
#include "Skin.h"
class Heros :
	public Id
{
public:
	Skin skin;
	Heros(Skin skin);
	Heros();
	~Heros();
};

