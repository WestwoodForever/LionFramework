#pragma once

#include "core/EventCustomComponent.h"
//class cocos2d::Touch;
//class cocos2d::Event;
//class cocos2d::EventCustom;

namespace InputFeature
{

class InputComponent : public Core::EventCustomComponent
{
	DECLARE_CLASS_COMPONENT_INFO
	CREATE_FUNC(InputComponent);
public:
	InputComponent();
	~InputComponent();

	bool init() override;

	void onEnter() override;
	void update(float delta) override;
	void onExit() override;

protected:
	void setupAttributes();
	void setupEventCustom();
	
	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);
	void onMouseScroll(cocos2d::Event* event);
};

}