#include "aifeature\fsm/StateMachine.h"

#include "aifeature/states/state.h"

namespace Lion
{

StateMachine::StateMachine():
_entity(nullptr),
_currentState(nullptr)
{

}

StateMachine::~StateMachine()
{
	setEntity(nullptr);
	_stateMap.clear();
}

bool StateMachine::init()
{

	return true;
}

void StateMachine::onEnter()
{
	CCASSERT(getEntity() != nullptr, "fsm entity is null.");
	CCASSERT(_stateMap.empty() == false, "fsm not states.");
	CCASSERT(checkTransitionTargetStates() == true, "Transitions target state check error.");
	setCurrentState(_stateMap.begin()->second);
}

bool StateMachine::checkTransitionTargetStates()
{
	bool success = true;
	for (auto iter = _stateMap.begin(); iter != _stateMap.end(); ++iter)
	{
		State* state = iter->second;

		int transIndex;
		Transition* transition = nullptr;
		
		for (transIndex = 0; transIndex < state->getTransitionCount(); transIndex++)
		{
			transition = state->getTransition(transIndex);
			auto targetStateName = transition->getTargetStateName();
			
			if (_stateMap.at(targetStateName) == nullptr)
			{
				CCLOGERROR("target state '%s' not defined. owner state '%s'"
					, targetStateName.c_str()
					, state->getName().c_str());
				success = false;
			}
		}
	}
	return success;
}

void StateMachine::update(float delta)
{
	auto curState = getCurrentState();
	CCASSERT(curState != nullptr, "current state is nullptr");
	curState->update(delta);

	auto transition = curState->evaluateTransition();
	if (transition != nullptr)
	{
		curState->onExit();
		auto targetState = _stateMap.at(transition->getTargetStateName());
		if (targetState != nullptr)
		{
			setCurrentState(targetState);
		}
	}
}

void StateMachine::onExit()
{
	getCurrentState()->onExit();
}

void StateMachine::addState(State* state)
{
	state->setEntity(getEntity());
	_stateMap.insert(state->getName(), state);
}

void StateMachine::setCurrentState(State* state)
{
	_currentState = state;
	state->onEnter();
}

}
