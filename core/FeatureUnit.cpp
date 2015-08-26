#include "core/FeatureUnit.h"

#include "core\Manager.h"

namespace Core
{

FeatureUnit::FeatureUnit()
{

}

FeatureUnit::~FeatureUnit()
{
	_managers.clear();
}

bool FeatureUnit::init()
{
	SetupManangers();
	registComponentType();
	return true;
}

void FeatureUnit::onEnter()
{
	for (auto manager : _managers)
	{
		manager->onEnter();
	}
}

void FeatureUnit::update(float delta)
{
	for (auto manager : _managers)
	{
		manager->update(delta);
	}
}

void FeatureUnit::onExit()
{
	for (auto manager : _managers)
	{
		manager->onExit();
	}
}

void FeatureUnit::addManager(Manager* manager)
{
	_managers.pushBack(manager);
}

void FeatureUnit::SetupManangers()
{

}

void FeatureUnit::registComponentType()
{

}

}
