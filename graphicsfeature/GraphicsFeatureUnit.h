#pragma once

#include "core\FeatureUnit.h"

namespace Lion
{

class GraphicsFeatureUnit : public FeatureUnit
{
public:
	CREATE_FUNC(GraphicsFeatureUnit);

	GraphicsFeatureUnit();
	~GraphicsFeatureUnit();

	virtual bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void registComponentType() override;
};

}