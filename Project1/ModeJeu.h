#pragma once
#include "Id.h"
class ModeJeu :
	public Id
{
public:
	int malusAtt;
	ModeJeu(int malusAtt);
	ModeJeu();
	~ModeJeu();
};

namespace modes
{

	extern const ModeJeu standard;
	extern const ModeJeu malusLeger;
}