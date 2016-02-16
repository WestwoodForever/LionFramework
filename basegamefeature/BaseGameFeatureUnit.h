#pragma once

#include "core\FeatureUnit.h"

namespace Lion
{

class BaseGameFeatureUnit : public FeatureUnit
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