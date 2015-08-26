#include "core\EventCustomComponent.h"

namespace Core
{

EventCustomComponent::EventCustomComponent()
{

}

EventCustomComponent::~EventCustomComponent()
{

}

bool EventCustomComponent::init()
{
	setupEventCustom();
	return Component::init();
}

void EventCustomComponent::onEnter()
{
	setupAttributes();
	Component::onEnter();
}

void EventCustomComponent::update(float delta)
{
	Component::update(delta);
}

void EventCustomComponent::onExit()
{
	Component::onExit();
}

}