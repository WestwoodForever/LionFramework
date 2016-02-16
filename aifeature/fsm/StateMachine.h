#pragma once

#include "2d\CCNode.h"
#include "base\CCMap.h"

namespace Lion
{

class State;

class StateMachine : public cocos2d::Ref
{
public:
	CREATE_FUNC(StateMachine);

public:
	StateMachine();
	~StateMachine();

	bool init();

	void onEnter();
	void update(float delta);
	void onExit();

	void addState(State* state);

	//HandleMessage

	CC_SYNTHESIZE(cocos2d::Node*, _entity, Entity);
	CC_SYNTHESIZE_READONLY(State*, _currentState, CurrentState);

protected:
	void setCurrentState(State* state);
	bool checkTransitionTargetStates();

private:
	cocos2d::Map<std::string, State*> _stateMap;
};

}