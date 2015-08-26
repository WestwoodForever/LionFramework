#pragma once

#include "base/CCRef.h"
#include "base\CCVector.h"

namespace Core
{

class Manager;

class FeatureUnit : public cocos2d::Ref
{
public:
	FeatureUnit();
	virtual ~FeatureUnit();

	virtual bool init();

	virtual void onEnter();
	virtual void update(float delta);
	virtual void onExit();

protected:
	void addManager(Manager* manager);

	virtual void SetupManangers();
	virtual void registComponentType();

private:
	cocos2d::Vector<Manager*> _managers;
};

}