#include "aifeature/states/BattleIdleState.h"

#include "2d/CCSpriteFrame.h"
#include "2d/CCSpriteFrameCache.h"

#include "2d/CCAnimation.h"
#include "2d/CCAction.h"
#include "2d/CCActionInterval.h"

#include "aifeature/transitions/BattleIdleToBattleRunTransition.h"

USING_NS_CC;

namespace Lion
{

BattleIdleState::BattleIdleState()
{

}

BattleIdleState::~BattleIdleState()
{

}

bool BattleIdleState::init()
{
	setName("BattleIdleState");

	auto transition = BattleIdleToBattleRunTransition::create();
	addTransition(transition);

	return State::init();
}

void BattleIdleState::onEnter()
{
	// Idle 애니메이션 액션
	State::onEnter();

	Vector<SpriteFrame*> animFrames(3);
	char str[100] = { 0, };
	auto spritecache = SpriteFrameCache::getInstance();

	for (int i = 1; i <= 3; i++)
	{
		sprintf(str, "leon_idle_battle_south_%d.png", i);
		auto frame = spritecache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
	auto sprite = getEntity()->getChildByTag(1000);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
}

void BattleIdleState::update(float delta)
{
	State::update(delta);
}

void BattleIdleState::onExit()
{
	State::onExit();
}

}