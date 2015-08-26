#pragma once

#include "core\FeatureUnit.h"

namespace AIFeature
{

class AIFeatureUnit : public Core::FeatureUnit
{
public:
	CREATE_FUNC(AIFeatureUnit);

	AIFeatureUnit();
	~AIFeatureUnit();

	virtual bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void registComponentType() override;
};

}