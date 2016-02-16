#include "inputfeature/components/FocusableComponent.h"

//#include "2d\CCNode.h"
#include "base\CCEventListenerTouch.h"
#include "base\CCEventDispatcher.h"
#include "base\CCTouch.h"
#include "base\CCEvent.h"
#include "base\CCDirector.h"

USING_NS_CC;

namespace Lion
{

IMPLEMENT_CLASS_COMPONENT_INFO(FocusableComponent)

FocusableComponent::FocusableComponent()
{
	//Grabbed, Ungrabbed
}

FocusableComponent::~FocusableComponent()
{

}

bool FocusableComponent::init()
{
	setName("FocusableComponent");
	return true;
}

void FocusableComponent::setupAttributes()
{

}

void FocusableComponent::setupEventCustom()
{

}

void FocusableComponent::onEnter()
{
	EventCustomComponent::onEnter();
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(FocusableComponent::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(FocusableComponent::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(FocusableComponent::onTouchEnded, this);

	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getOwner());
}

void FocusableComponent::update(float delta)
{

}

void FocusableComponent::onExit()
{

}

bool FocusableComponent::onTouchBegan(Touch* touch, Event* event)
{
	//if (getOwner()->getName() == "Leon")
	{
		CCLOG("'%s' FocusableComponent::onTouchBegan id = %d, x = %f, y = %f", getOwner()->getName().c_str(), touch->getID(), touch->getLocation().x, touch->getLocation().y);
	}
	return true;
}

void FocusableComponent::onTouchMoved(Touch* touch, Event* event)
{
	CCLOG("'%s'FocusableComponent::onTouchMoved id = %d, x = %f, y = %f", getOwner()->getName().c_str(), touch->getID(), touch->getLocation().x, touch->getLocation().y);

}

void FocusableComponent::onTouchEnded(Touch* touch, Event* event)
{

}

}