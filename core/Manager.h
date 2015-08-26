#pragma once

#include "base/CCRef.h"

namespace Core
{

class Manager : public cocos2d::Ref
{
public:
	Manager();
	virtual ~Manager();

	virtual bool init();

	virtual void onEnter();
	virtual void update(float delta);
	virtual void onExit();

};

}