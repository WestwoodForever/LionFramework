#pragma once

#include "aifeature/states/State.h"

namespace AIFeature
{

class BattleIdleState : public State
{
public:
	BattleIdleState();
	virtual ~BattleIdleState();
	CREATE_FUNC(BattleIdleState);

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void update(float delta) override;
	virtual void onExit() override;
};

}