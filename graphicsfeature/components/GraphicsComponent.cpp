#include "graphicsfeature/components/GraphicsComponent.h"

#include "base\CCDirector.h"
#include "base\CCVector.h"

#include "2d/CCSprite.h"
#include "2d/CCSpriteFrameCache.h"

#include "basegamefeature/components/AttributeComponent.h"

#include "base\CCEventDispatcher.h"
#include "inputfeature/InputEventCustom.h"

USING_NS_CC;

namespace Lion
{

IMPLEMENT_CLASS_COMPONENT_INFO(GraphicsComponent)

GraphicsComponent::GraphicsComponent()
{
}

GraphicsComponent::~GraphicsComponent()
{

}

bool GraphicsComponent::init()
{
	EventCustomComponent::init();
	setName("GraphicsComponent");
	return true;
}

void GraphicsComponent::setupAttributes()
{
	auto component = getOwner()->getComponent("AttributeComponent");
	CCASSERT(component != nullptr, "attr component not found.");
	AttributeComponent* attributeComponent = (AttributeComponent*)component;
	attributeComponent->setString(Attr::Graphics, "Sprite/leon_battleidle.plist");
}

void GraphicsComponent::setupEventCustom()
{

}

void GraphicsComponent::onEnter()
{
	EventCustomComponent::onEnter();
	auto spritecache = SpriteFrameCache::getInstance();

	auto component = getOwner()->getComponent("AttributeComponent");
	if (component != nullptr)
	{
		AttributeComponent* attributeComponent = (AttributeComponent*)component;
		auto graphicsString = attributeComponent->getString(Attr::Graphics);

		//TODO 게임 오브젝트 관련된 그래픽 데이터 읽어오도록
		spritecache->addSpriteFramesWithFile(graphicsString);
	}

	auto gameobject = getOwner();
	// TODO 읽어온 이미지 addChild한다.
	auto s = Director::getInstance()->getWinSize();

	auto sprite = Sprite::createWithSpriteFrameName("leon_idle_battle_south_1.png");
	gameobject->addChild(sprite, sprite->getLocalZOrder(), 1000);
	gameobject->setPosition(Vec2(s.width / 3 - 3, s.height / 3 - 13));

	/*spritecache->addSpriteFramesWithFile("Sprite/System.plist");
	sprite = Sprite::createWithSpriteFrameName("System/Cursor.png");
	gameobject->addChild(sprite, -1, 1000);*/
}

void GraphicsComponent::onExit()
{
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("Sprite/leon_battleidle.plist");
	EventCustomComponent::onExit();
}

}