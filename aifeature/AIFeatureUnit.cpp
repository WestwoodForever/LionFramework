#include "AIFeature\AIFeatureUnit.h"

#include "base\ObjectFactory.h"

#include "AIFeature\components\BehaviourComponent.h"

USING_NS_CC;

namespace Lion
{

AIFeatureUnit::AIFeatureUnit()
{

}

AIFeatureUnit::~AIFeatureUnit()
{

}

bool AIFeatureUnit::init()
{
	FeatureUnit::init();
	return true;
}

void AIFeatureUnit::onEnter()
{
	FeatureUnit::onEnter();
}

void AIFeatureUnit::update(float delta)
{
	FeatureUnit::update(delta);
}

void AIFeatureUnit::onExit()
{
	FeatureUnit::onExit();
}

void AIFeatureUnit::registComponentType()
{
	FeatureUnit::registComponentType();

	auto objfactory = ObjectFactory::getInstance();
	objfactory->registerType(CREATE_CLASS_COMPONENT_INFO(BehaviourComponent));
}

}