#include "core\Framework.h"

#include "core\FeatureUnit.h"

namespace Lion
{

Framework::Framework()
{

}

Framework::~Framework()
{
	_featureunits.clear();
}

bool Framework::init()
{
	SetupFeatures();
	return true;
}

void Framework::start()
{
	for (auto featureunit : _featureunits)
	{
		featureunit->onEnter();
	}
}

void Framework::update(float delta)
{
	for (auto featureunit : _featureunits)
	{
		featureunit->update(delta);
	}
}

void Framework::end()
{
	for (auto featureunit : _featureunits)
	{
		featureunit->onExit();
	}
}

void Framework::addFeature(FeatureUnit* featureunit)
{
	CCASSERT(featureunit, "featureunit is null");
	_featureunits.pushBack(featureunit);
}

void Framework::SetupFeatures()
{

}

}