#pragma once

#include "aifeature/transitions/Transition.h"

namespace Lion
{

class BattleIdleToBattleRunTransition : public Transition
{
public:
	BattleIdleToBattleRunTransition();
	~BattleIdleToBattleRunTransition();

	CREATE_FUNC(BattleIdleToBattleRunTransition);

	bool init() override;
	bool evaluateConditions() override;
};

}