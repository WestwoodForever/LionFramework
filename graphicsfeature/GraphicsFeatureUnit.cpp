#include "GraphicsFeature\GraphicsFeatureUnit.h"

#include "base\ObjectFactory.h"

#include "GraphicsFeature\components\GraphicsComponent.h"

USING_NS_CC;

namespace GraphicsFeature
{

GraphicsFeatureUnit::GraphicsFeatureUnit()
{

}

GraphicsFeatureUnit::~GraphicsFeatureUnit()
{

}

bool GraphicsFeatureUnit::init()
{
	FeatureUnit::init();
	return true;
}

void GraphicsFeatureUnit::onEnter()
{
	FeatureUnit::onEnter();
}

void GraphicsFeatureUnit::update(float delta)
{
	FeatureUnit::update(delta);
}

void GraphicsFeatureUnit::onExit()
{
	FeatureUnit::onExit();
}

void GraphicsFeatureUnit::registComponentType()
{
	FeatureUnit::registComponentType();

	auto objfactory = ObjectFactory::getInstance();
	objfactory->registerType(CREATE_CLASS_COMPONENT_INFO(GraphicsComponent));
}

}