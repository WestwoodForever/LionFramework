#pragma once

#include "core/Manager.h"
#include "base\CCRefPtr.h"

#include "core/singleton.h"
#include "basegamefeature/BluePrints.h"

namespace Lion
{

class FactoryManager : public Manager
{
	DECLARE_SINGLETON(FactoryManager);
public:
	CREATE_FUNC(FactoryManager);

	FactoryManager();
	~FactoryManager();

	bool init() override;

	void onEnter() override;
	void onExit() override;

	cocos2d::Node* createEntityByType(const std::string type);

private:
	cocos2d::RefPtr<BluePrints> _blueprints;
};

}