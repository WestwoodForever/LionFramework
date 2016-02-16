#pragma once

#include "core\FeatureUnit.h"

namespace Lion
{

class InputFeatureUnit : public FeatureUnit
{
public:
	CREATE_FUNC(InputFeatureUnit);

	InputFeatureUnit();
	~InputFeatureUnit();

	virtual bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void SetupManangers() override;
	void registComponentType() override;
};

}