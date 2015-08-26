#pragma once

#include "base\CCEventCustom.h"
#include "base\CCEventListener.h"
#include "math\Vec2.h"

namespace Input
{

const cocos2d::EventListener::ListenerID LID_MoveDirection("MoveDirection");
/*
class MoveDirection : public cocos2d::EventCustom
{
public:
	MoveDirection() :EventCustom(LID_MoveDirection),
		_direction(cocos2d::Vec2::ZERO)
	{

	}

	void setDirection(const cocos2d::Vec2 direction)
	{
		_direction = direction;
	}

	const cocos2d::Vec2& getDirection() const
	{
		return _direction;
	}

private:
	cocos2d::Vec2 _direction;
};
*/
const cocos2d::EventListener::ListenerID LID_MoveGoto("MoveGoto");
/*
class MoveGoto : public cocos2d::EventCustom
{
public:
	MoveGoto() :EventCustom(LID_MoveGoto),
		_position(cocos2d::Vec2::ZERO)
	{

	}

	void setPosition(const cocos2d::Vec2 position)
	{
		_position = position;
	}

	const cocos2d::Vec2& getPosition() const
	{
		return _position;
	}

private:
	cocos2d::Vec2 _position;
};
*/
}