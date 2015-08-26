#pragma once

#include "base/CCRef.h"
//#include "base/CCVector.h"
#include <string>

namespace AIFeature
{

class Transition : public cocos2d::Ref
{
public:
	Transition();
	virtual ~Transition();

	virtual bool init();

	/*virtual void onEnter();
	virtual void onUpdate(float delta);
	virtual void onExit();*/

	virtual bool evaluateConditions();

	//CC_SYNTHESIZE(std::string, _name, Name);
	CC_SYNTHESIZE(std::string, _targetStateName, TargetStateName);
	//cocos2d::Vector<Transition*> _transitions;

};

}