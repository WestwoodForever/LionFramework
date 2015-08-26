#pragma once

#include "core/EventCustomComponent.h"

//class cocos2d::Touch;
//class cocos2d::Event;
//class cocos2d::EventCustom;

namespace InputFeature
{

class FocusableComponent : public Core::EventCustomComponent
{
	DECLARE_CLASS_COMPONENT_INFO
	CREATE_FUNC(FocusableComponent);
public:
	FocusableComponent();
	~FocusableComponent();

	bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void setupAttributes();
	void setupEventCustom();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

}