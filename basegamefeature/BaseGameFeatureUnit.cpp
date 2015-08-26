#include "basegamefeature\BaseGameFeatureUnit.h"

#include "base\ObjectFactory.h"

#include "basegamefeature\managers\GameStateManager.h"
#include "basegamefeature\managers\FactoryManager.h"
#include "basegamefeature\managers\DataTableManager.h"

#include "basegamefeature\components\AttributeComponent.h"

USING_NS_CC;

namespace BaseGameFeature
{

BaseGameFeatureUnit::BaseGameFeatureUnit()
{

}

BaseGameFeatureUnit::~BaseGameFeatureUnit()
{

}

bool BaseGameFeatureUnit::init()
{
	FeatureUnit::init();
	return true;
}

void BaseGameFeatureUnit::onEnter()
{
	FeatureUnit::onEnter();
}

void BaseGameFeatureUnit::update(float delta)
{
	FeatureUnit::update(delta);
}

void BaseGameFeatureUnit::onExit()
{
	FeatureUnit::onExit();
}

void BaseGameFeatureUnit::SetupManangers()
{
	FeatureUnit::SetupManangers();
	addManager(FactoryManager::create());
	addManager(GameStateManager::create());
	addManager(DataTableManager::create());
}

void BaseGameFeatureUnit::registComponentType()
{
	FeatureUnit::registComponentType();

	auto objfactory = ObjectFactory::getInstance();
	objfactory->registerType(CREATE_CLASS_COMPONENT_INFO(AttributeComponent));
}

}