#include "aifeature/states/State.h"

#include "2d\CCNode.h"

USING_NS_CC;

namespace Lion
{

State::State():
_entity(nullptr)
{

}

State::~State()
{
	setEntity(nullptr);
	_transitions.clear();
}

bool State::init()
{
	CCASSERT(getName().empty() == false, "State name is null");
	for (auto transition : _transitions)
	{
		transition->init();
	}
	return true;
}

void State::onEnter()
{
	CCASSERT(getEntity() != nullptr, "state entity is null.");
	CCLOG("'%s':'%s' state enter.", getEntity()->getName().c_str(), getName().c_str());
	CCASSERT(_transitions.size() > 0, "state transition size is zero.");
}

void State::update(float delta)
{

}

void State::onExit()
{

}

Transition* State::getTransition(int transIndex)
{
	return _transitions.at(transIndex);
}

int State::getTransitionCount()
{
	return _transitions.size();
}

void State::addTransition(Transition* transition)
{
	_transitions.pushBack(transition);
}

Transition* State::evaluateTransition()
{
	for (auto transition : _transitions)
	{
		if (transition->evaluateConditions() == true)
			return transition;
	}
	return nullptr;
}

}
