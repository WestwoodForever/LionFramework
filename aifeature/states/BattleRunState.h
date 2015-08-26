#pragma once

#include "aifeature/states/State.h"

namespace AIFeature
{

class BattleRunState : public State
{
public:
	BattleRunState();
	virtual ~BattleRunState();
	CREATE_FUNC(BattleRunState);

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void update(float delta) override;
	virtual void onExit() override;
};

}