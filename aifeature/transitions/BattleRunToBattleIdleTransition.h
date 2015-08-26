#pragma once

#include "aifeature/transitions/Transition.h"

namespace AIFeature
{

class BattleRunToBattleIdleTransition : public Transition
{
public:
	BattleRunToBattleIdleTransition();
	~BattleRunToBattleIdleTransition();

	CREATE_FUNC(BattleRunToBattleIdleTransition);
};

}