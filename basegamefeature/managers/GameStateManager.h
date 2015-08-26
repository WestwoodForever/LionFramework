#pragma once

#include "core/Manager.h"

namespace BaseGameFeature
{

class GameStateManager : public Core::Manager
{
public:
	CREATE_FUNC(GameStateManager);

	GameStateManager();
	~GameStateManager();

	bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;
};

}