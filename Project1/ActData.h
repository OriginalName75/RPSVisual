#pragma once
#include "Block.h"
#include "Attack.h"
#include <vector>
#include "Cancel.h"

namespace typeAttack
{

	extern const TypeAttack null;
	extern const TypeAttack pierre;
	extern const TypeAttack feuille ;
	extern const TypeAttack ciseaux;
	extern const std::vector<TypeAttack> listtypeAttack;
}
namespace actionsSkin
{
	extern const Id normal;
	extern const Id attack;
	extern const Id block;
	extern const Id preparing;
	extern const Id stun;
	extern const std::vector<Id> actions;
}
namespace actionFrames
{
	extern const ActionFrame idle;
	extern const ActionFrame  preparing;
	extern const ActionFrame  fast_cissors;
	extern const ActionFrame  fast_sheet;
	extern const ActionFrame  fast_stone;
	extern const ActionFrame  heavy_cissors;
	extern const ActionFrame  heavy_sheet;
	extern const ActionFrame  heavy_stone;
	extern const ActionFrame  stone;
	extern const ActionFrame  sheet;
	extern const ActionFrame  cissors;
	extern const ActionFrame  protect_cissors;
	extern const ActionFrame  protect_sheet;
	extern const ActionFrame  protect_stone;
	extern const ActionFrame  stun;
	extern const ActionFrame  endlag;
	extern const std::vector<ActionFrame> listProtect;
}

namespace actions
{


	extern const Action* const light;
	extern const Action* const meduim;
	extern const Action* const heavy;
	extern const Action* const block;
	extern const Action* const cancel;
	extern const std::vector<const Action*> listAction;
}
