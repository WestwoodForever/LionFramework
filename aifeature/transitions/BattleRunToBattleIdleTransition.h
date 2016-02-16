#pragma once

#include "aifeature/transitions/Transition.h"

namespace Lion
{

class BattleRunToBattleIdleTransition : public Transition
{
public:
	BattleRunToBattleIdleTransition();
	~BattleRunToBattleIdleTransition();

	CREATE_FUNC(BattleRunToBattleIdleTransition);
};

}