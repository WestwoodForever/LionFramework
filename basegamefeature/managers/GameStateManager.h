#pragma once

#include "core/Manager.h"

namespace Lion
{

class GameStateManager : public Manager
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