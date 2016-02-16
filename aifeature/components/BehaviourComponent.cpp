#include "aifeature/components/BehaviourComponent.h"

#include "aifeature/fsm/StateMachine.h"

#include "aifeature/states/BattleIdleState.h"
#include "aifeature/states/BattleRunState.h"

namespace Lion
{

IMPLEMENT_CLASS_COMPONENT_INFO(BehaviourComponent)

BehaviourComponent::BehaviourComponent():
_stateMachine(nullptr)
{

}

BehaviourComponent::~BehaviourComponent()
{

}

bool BehaviourComponent::init()
{
	setName("BehaviourComponent");
	_stateMachine = StateMachine::create();
	return true;
}

void BehaviourComponent::onEnter()
{
	//auto stateMachine = getStateMachine();
	auto entity = getOwner();
	_stateMachine->setEntity(entity);

	State* state = BattleIdleState::create();
	_stateMachine->addState(state);

	state = BattleRunState::create();
	_stateMachine->addState(state);

	_stateMachine->onEnter();
}

void BehaviourComponent::update(float delta)
{
	//auto stateMachine = getStateMachine();
	_stateMachine->update(delta);
}

void BehaviourComponent::onExit()
{
	//auto stateMachine = getStateMachine();
	_stateMachine->onExit();
}

}