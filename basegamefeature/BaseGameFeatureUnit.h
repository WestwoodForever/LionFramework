#pragma once

#include "core\FeatureUnit.h"

namespace BaseGameFeature
{

class BaseGameFeatureUnit : public Core::FeatureUnit
{
public:
	CREATE_FUNC(BaseGameFeatureUnit);

	BaseGameFeatureUnit();
	~BaseGameFeatureUnit();

	virtual bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void SetupManangers() override;
	void registComponentType() override;
};

}