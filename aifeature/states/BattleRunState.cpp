#include "aifeature/states/BattleRunState.h"

namespace Lion
{

BattleRunState::BattleRunState()
{

}

BattleRunState::~BattleRunState()
{

}

bool BattleRunState::init()
{
	setName("BattleRunState");
	return State::init();
}

void BattleRunState::onEnter()
{
	State::onEnter();
}

void BattleRunState::update(float delta)
{
	State::update(delta);
}

void BattleRunState::onExit()
{
	State::onExit();
}

}