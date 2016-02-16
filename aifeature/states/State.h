#pragma once

#include "base/CCRef.h"
#include "base/CCVector.h"
#include <string>

#include "aifeature/transitions/Transition.h"

namespace Lion
{

class State : public cocos2d::Ref
{
public:
	State();
	virtual ~State();

	virtual bool init();

	virtual void onEnter();
	virtual void update(float delta);
	virtual void onExit();

	Transition* getTransition(int transIndex);
	int getTransitionCount();

	virtual Transition* evaluateTransition();

	CC_SYNTHESIZE(cocos2d::Node*, _entity, Entity);
	CC_SYNTHESIZE(std::string, _name, Name);

protected:
	void addTransition(Transition* transition);

private:
	cocos2d::Vector<Transition*> _transitions;
};

}