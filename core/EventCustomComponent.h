#pragma once

#include "2d\CCComponent.h"
#include "editor-support\cocostudio\CCComBase.h"

namespace Core
{

class EventCustomComponent : public cocos2d::Component
{
public:
	EventCustomComponent();
	virtual ~EventCustomComponent();

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void update(float delta);
	virtual void onExit() override;

protected:
	virtual void setupAttributes() abstract;
	virtual void setupEventCustom() abstract;

};

}