#pragma once

#include "2d/CCLayer.h"
#include "2d/CCScene.h"

class GameLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameLayer);
};