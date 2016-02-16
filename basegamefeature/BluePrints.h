#pragma once

#include "base\CCRef.h"
#include "platform\CCSAXParser.h"
#include "base\CCVector.h"

namespace Lion
{

const std::string BLUEPRINT_FILENAME = "Data/blueprints.xml";

class BluePrint : public cocos2d::Ref
{
public:
	BluePrint(){}
	~BluePrint(){}
	CREATE_FUNC(BluePrint);

	bool init()
	{
		_type = "none";
		return true;
	}

	void addComponent(std::string componentName)
	{
		CCASSERT(componentName.empty() == false, "Blueprint component name is null.");
		_components.push_back(componentName);
	}

	std::string _type;
	std::vector<std::string> _components;
};

class BluePrints : public cocos2d::Ref, public cocos2d::SAXDelegator
{
public:
	BluePrints();
	~BluePrints();
	CREATE_FUNC(BluePrints);

	bool init();
	bool parseXMLFile(const std::string& xmlFilename);
	BluePrint* findBluePrint(const std::string& entityType);

protected:
	// implement pure virtual methods of CCSAXDelegator
	void startElement(void *ctx, const char *name, const char **atts);
	void endElement(void *ctx, const char *name);
	void textHandler(void *ctx, const char *ch, int len);

private:
	cocos2d::Vector<BluePrint*> _blueprints;
};
}