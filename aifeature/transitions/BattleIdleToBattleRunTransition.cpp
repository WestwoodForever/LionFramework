#include "aifeature/transitions/BattleIdleToBattleRunTransition.h"

namespace Lion
{

BattleIdleToBattleRunTransition::BattleIdleToBattleRunTransition()
{

}

BattleIdleToBattleRunTransition::~BattleIdleToBattleRunTransition()
{

}

bool BattleIdleToBattleRunTransition::init()
{
	Transition::init();
	setTargetStateName("BattleRunState");
	return true;
}

bool BattleIdleToBattleRunTransition::evaluateConditions()
{

	return false;
}

}