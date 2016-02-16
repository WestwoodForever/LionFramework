#pragma once

#include "2d\CCComponent.h"
#include "editor-support\cocostudio\CCComBase.h"

#include "base\CCRefPtr.h"

namespace Lion
{

class StateMachine;

class BehaviourComponent : public cocos2d::Component
{
	DECLARE_CLASS_COMPONENT_INFO;
	CREATE_FUNC(BehaviourComponent);
public:
	BehaviourComponent();
	~BehaviourComponent();

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void update(float delta) override;
	virtual void onExit() override;

	cocos2d::RefPtr<StateMachine> _stateMachine;
	//CC_SYNTHESIZE(, _stateMachine, StateMachine);
};

}