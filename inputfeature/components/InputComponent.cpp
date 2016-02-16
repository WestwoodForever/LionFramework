#include "inputfeature/components/InputComponent.h"

//#include "2d\CCNode.h"
#include "base\CCEventDispatcher.h"
#include "base\CCEventListenerMouse.h"
#include "base\CCDirector.h"

USING_NS_CC;

namespace Lion
{

IMPLEMENT_CLASS_COMPONENT_INFO(InputComponent)

InputComponent::InputComponent()
{
	//Grabbed, Ungrabbed
}

InputComponent::~InputComponent()
{

}

bool InputComponent::init()
{
	setName("InputComponent");
	return true;
}

void InputComponent::setupAttributes()
{

}

void InputComponent::setupEventCustom()
{

}

void InputComponent::onEnter()
{
	EventCustomComponent::onEnter();
	auto listener = EventListenerMouse::create();
	
	listener->onMouseMove = CC_CALLBACK_1(InputComponent::onMouseMove, this);
	listener->onMouseUp = CC_CALLBACK_1(InputComponent::onMouseUp, this);
	listener->onMouseDown = CC_CALLBACK_1(InputComponent::onMouseDown, this);
	listener->onMouseScroll = CC_CALLBACK_1(InputComponent::onMouseScroll, this);

	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getOwner());
}

void InputComponent::update(float delta)
{

}

void InputComponent::onExit()
{

}

void InputComponent::onMouseDown(cocos2d::Event* event)
{
	EventMouse* e = (EventMouse*)event;

	CCLOG("'%s'InputComponent::onMouseDown Key = %d, x:%f, y:%f", getOwner()->getName().c_str(), e->getMouseButton(), e->getCursorX(), e->getCursorY());
}

void InputComponent::onMouseUp(cocos2d::Event* event)
{

}

void InputComponent::onMouseMove(cocos2d::Event* event)
{

}

void InputComponent::onMouseScroll(cocos2d::Event* event)
{

}

}