#pragma once

#include "core\FeatureUnit.h"

namespace GraphicsFeature
{

class GraphicsFeatureUnit : public Core::FeatureUnit
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