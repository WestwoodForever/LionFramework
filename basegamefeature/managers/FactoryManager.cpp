#include "basegamefeature/managers/FactoryManager.h"

#include "base\CCDirector.h"
#include "base\ObjectFactory.h"
#include "2d\CCComponent.h"

USING_NS_CC;

namespace BaseGameFeature
{

IMPLEMENT_SINGLETON(FactoryManager);

FactoryManager::FactoryManager():
_blueprints(nullptr)
{
	CONSTRUCT_SINGLETON;
}

FactoryManager::~FactoryManager()
{
	DESTRUCT_SINGLETON;
}

bool FactoryManager::init()
{
	_blueprints = BluePrints::create();
	return true;
}

void FactoryManager::onEnter()
{
	CCASSERT(_blueprints->parseXMLFile(BLUEPRINT_FILENAME) == true, "error blueprints parse.");
}

void FactoryManager::onExit()
{
	
}
Node* FactoryManager::createEntityByType(const std::string type)
{
	Node* entity = Node::create();

	auto blueprint = _blueprints->findBluePrint(type);
	CCASSERT(blueprint != nullptr, "blueprint not found.");

	for (auto componentName : blueprint->_components)
	{
		auto component = dynamic_cast<Component*>(ObjectFactory::getInstance()->createObject(componentName));
		// todo add attr
		entity->addComponent(component);
	}
	
	return entity;
}

}