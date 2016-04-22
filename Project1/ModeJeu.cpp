#include "ModeJeu.h"



ModeJeu::ModeJeu(int malusAtt)
{
	this->malusAtt = malusAtt;
}

ModeJeu::ModeJeu():ModeJeu(0)
{
}


ModeJeu::~ModeJeu()
{
}
namespace modes
{

	const ModeJeu standard= ModeJeu();
	const ModeJeu malusLeger = ModeJeu(2);
}