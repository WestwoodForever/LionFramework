#pragma once

#include "base\CCDirector.h"
#include "basegamefeature/managers/GameStateManager.h"

#include "GameLayer.h"

USING_NS_CC;

namespace BaseGameFeature
{

GameStateManager::GameStateManager()
{

}

GameStateManager::~GameStateManager()
{

}

bool GameStateManager::init()
{
	
	return true;
}

void GameStateManager::onEnter()
{
	auto scene = GameLayer::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameStateManager::update(float delta)
{

}

void GameStateManager::onExit()
{

}

}