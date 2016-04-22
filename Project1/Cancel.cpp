#include "Cancel.h"


Cancel::Cancel(sf::Keyboard::Key player1, sf::Keyboard::Key player2):Action(player1, player2)
{

}

Cancel::Cancel()
{
}

Cancel::~Cancel()
{
}

void Cancel::keyOnly(FutureAction * t, int player) const
{
	
	if ((player==1 && t->p1->blockCD==0) || (player == 2 && t->p2->blockCD == 0)) {
		if (player == 1) {
			t->player1.clear();
			t->p1->blockCD = 30;
			t->p1->majLife();
		}
		else {
			t->player2.clear();
			
			t->p2->blockCD = 30;
			t->p2->majLife();
		}
		std::cout << " cancel" << std::endl;
		t->maj();
		
	}

	
}
