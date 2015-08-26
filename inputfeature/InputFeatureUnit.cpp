#include "InputFeature\InputFeatureUnit.h"

#include "base\ObjectFactory.h"

#include "InputFeature\components\FocusableComponent.h"
#include "InputFeature\components\InputComponent.h"

USING_NS_CC;

namespace InputFeature
{

InputFeatureUnit::InputFeatureUnit()
{

}

InputFeatureUnit::~InputFeatureUnit()
{

}

bool InputFeatureUnit::init()
{
	FeatureUnit::init();
	return true;
}

void InputFeatureUnit::onEnter()
{
	FeatureUnit::onEnter();
}

void InputFeatureUnit::update(float delta)
{
	FeatureUnit::update(delta);
}

void InputFeatureUnit::onExit()
{
	FeatureUnit::onExit();
}

void InputFeatureUnit::SetupManangers()
{
	FeatureUnit::SetupManangers();
}

void InputFeatureUnit::registComponentType()
{
	FeatureUnit::registComponentType();

	auto objfactory = ObjectFactory::getInstance();
	objfactory->registerType(CREATE_CLASS_COMPONENT_INFO(FocusableComponent));
	objfactory->registerType(CREATE_CLASS_COMPONENT_INFO(InputComponent));
}

}