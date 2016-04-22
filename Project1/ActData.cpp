#pragma once
#include "ActData.h"

namespace typeAttack
{

	const TypeAttack null = TypeAttack();
	const TypeAttack pierre = TypeAttack(sf::Keyboard::Key::A, sf::Keyboard::Key::U, {&ciseaux});
	const TypeAttack feuille = TypeAttack(sf::Keyboard::Key::Z, sf::Keyboard::Key::I, { &pierre });
	const TypeAttack ciseaux = TypeAttack(sf::Keyboard::Key::E, sf::Keyboard::Key::O, { &feuille });
	const std::vector<TypeAttack> listtypeAttack = { pierre ,feuille,ciseaux };
}
namespace actionsSkin
{
	const Id normal = Id("normal.png");
	const Id attack_sc = Id("Scissors.png");
	const Id attack_pa = Id("Paper.png");
	const Id attack_st = Id("Rock.png");
	const Id block = Id("normal.png");
	const Id preparing = Id("normal.png");
	const Id stun = Id("Stun.png");
	const std::vector<Id> actions = { normal , attack_sc ,attack_pa, attack_st, block , preparing , stun };

}

namespace actionFrames
{
	
	const ActionFrame  idle = ActionFrame("img/frame/idle.png");
	const ActionFrame  preparing =  ActionFrame("img/frame/endlag.png", actionsSkin::preparing);
	const ActionFrame  endlag = ActionFrame("img/frame/startup.png", actionsSkin::preparing);
	const ActionFrame  fast_cissors = ActionFrame("img/frame/light_scissors.png", typeAttack::ciseaux, actionsSkin::attack_sc);
	const ActionFrame  fast_sheet = ActionFrame("img/frame/light_paper.png", typeAttack::feuille, actionsSkin::attack_pa);
	const ActionFrame  fast_stone = ActionFrame("img/frame/light_rock.png", typeAttack::pierre, actionsSkin::attack_st);
	const ActionFrame  heavy_cissors = ActionFrame("img/frame/heavy_scissors.png", typeAttack::ciseaux, actionsSkin::attack_sc);
	const ActionFrame  heavy_sheet = ActionFrame("img/frame/heavy_paper.png", typeAttack::feuille, actionsSkin::attack_pa);
	const ActionFrame  heavy_stone = ActionFrame("img/frame/heavy_rock.png", typeAttack::pierre, actionsSkin::attack_st);
	const ActionFrame  stone = ActionFrame("img/frame/rock.png", typeAttack::pierre, actionsSkin::attack_st);
	const ActionFrame  sheet = ActionFrame("img/frame/paper.png", typeAttack::feuille, actionsSkin::attack_pa);
	const ActionFrame  cissors = ActionFrame("img/frame/scissors.png", typeAttack::ciseaux, actionsSkin::attack_sc);
	const ActionFrame  protect_cissors = ActionFrame("img/frame/guard_scissors.png", typeAttack::ciseaux, actionsSkin::block);
	const ActionFrame  protect_sheet = ActionFrame("img/frame/guard_paper.png", typeAttack::feuille, actionsSkin::block);
	const ActionFrame  protect_stone = ActionFrame("img/frame/guard_rock.png", typeAttack::pierre, actionsSkin::block);
	const ActionFrame  stun = ActionFrame("img/frame/stun.png", actionsSkin::stun);
	const std::vector<ActionFrame> listProtect = { protect_cissors , protect_sheet ,protect_stone };
}

namespace actions
{

	const Action* const light = new Attack(2, 2, 2, sf::Keyboard::Key::W, sf::Keyboard::Key::J, { actionFrames::fast_cissors ,actionFrames::fast_sheet, actionFrames::fast_stone }, { 6,4,2 }, 0,2);
	const Action* const meduim = new Attack(3, 4, 3, sf::Keyboard::Key::X, sf::Keyboard::Key::K, { actionFrames::cissors ,actionFrames::sheet, actionFrames::stone }, { 9,8,7,6,5 }, 1,5);
	const Action* const heavy = new Attack(5, 6, 10, sf::Keyboard::Key::C, sf::Keyboard::Key::L, { actionFrames::heavy_cissors ,actionFrames::heavy_sheet, actionFrames::heavy_stone }, { 10 }, 3,8);
	const Action* const block = new Block(1, 1, 2, sf::Keyboard::Key::V, sf::Keyboard::Key::M, { actionFrames::protect_cissors ,actionFrames::protect_sheet, actionFrames::protect_stone }, { 1 });
	const Action* const cancel = new Cancel(sf::Keyboard::Key::B, sf::Keyboard::Key::P);

	const std::vector<const Action*> listAction {light , meduim, heavy , block,cancel };

}

