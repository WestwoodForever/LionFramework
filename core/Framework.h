#pragma once

#include "base\CCVector.h"

namespace Core
{

class FeatureUnit;

class Framework
{
public:
	Framework();
	virtual ~Framework();

	virtual bool init();

	virtual void start();
	virtual void update(float delta);
	virtual void end();

protected:
	void addFeature(FeatureUnit* featureunit);
	virtual void SetupFeatures();

private:
	cocos2d::Vector<FeatureUnit*> _featureunits;
};

}