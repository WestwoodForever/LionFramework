#include "core\GameFramework.h"

#include "base\CCDirector.h"
#include "base/CCScheduler.h"

#include "basegamefeature\BaseGameFeatureUnit.h"
#include "graphicsfeature\GraphicsFeatureUnit.h"
#include "inputfeature\InputFeatureUnit.h"
#include "aifeature\AIFeatureUnit.h"

USING_NS_CC;

namespace Core
{

GameFramework* GameFramework::_sharedInstance = nullptr;

GameFramework* GameFramework::getInstance()
{
	if (_sharedInstance == nullptr)
	{
		_sharedInstance = new (std::nothrow) GameFramework();
	}
	return _sharedInstance;
}

void GameFramework::destroyInstance()
{
	CC_SAFE_DELETE(_sharedInstance);
}

GameFramework::GameFramework()
{

}

GameFramework::~GameFramework()
{

}

bool GameFramework::init()
{
	Framework::init();
	return true;
}

void GameFramework::start()
{
	Framework::start();
	Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}

void GameFramework::update(float delta)
{
	Framework::update(delta);
}

void GameFramework::end()
{
	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
	Framework::end();
}

void GameFramework::SetupFeatures()
{
	Framework::SetupFeatures();
	addFeature(BaseGameFeature::BaseGameFeatureUnit::create());
	addFeature(GraphicsFeature::GraphicsFeatureUnit::create());
	addFeature(InputFeature::InputFeatureUnit::create());
	addFeature(AIFeature::AIFeatureUnit::create());
}

}