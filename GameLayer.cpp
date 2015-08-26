#include "GameLayer.h"

#include "2d/CCTMXTiledMap.h"
#include "base\CCDirector.h"
#include "base/CCScheduler.h"

#include "basegamefeature\managers\FactoryManager.h"

USING_NS_CC;

Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	scene->setName("GameScene");
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init()
{
	if (Layer::init() == false)
		return false;

	setName("GameLayer");

	auto mapobject = BaseGameFeature::FactoryManager::getInstance()->createEntityByType("Map");
	mapobject->setName("testmap");
	//auto tilemap = TMXTiledMap::create("Map/ftr_test.tmx");
	//TODO �� �±װ�
	addChild(mapobject, 0, 1);

	auto gameobject = BaseGameFeature::FactoryManager::getInstance()->createEntityByType("Actor");
	gameobject->setName("Leon");

	addChild(gameobject);

	//������Ʈ update�� ���� �ӽ�. ���� GameObjectManager?
	Director::getInstance()->getScheduler()->scheduleUpdate(gameobject, 0, false);
	
	return true;
}