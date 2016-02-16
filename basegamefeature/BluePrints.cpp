#pragma once

#include "platform\CCFileUtils.h"

#include "basegamefeature\BluePrints.h"
#include "basegamefeature\managers\DataTableManager.h"

USING_NS_CC;

namespace Lion
{

BluePrints::BluePrints()
{

}

BluePrints::~BluePrints()
{

}

bool BluePrints::init()
{
	//CCASSERT(plist.size()>0, "Invalid texture file name");

	return true;
}

BluePrint* BluePrints::findBluePrint(const std::string& entityType)
{
	for (auto blueprint : _blueprints)
	{
		if (blueprint->_type == entityType)
			return blueprint;
	}
	return nullptr;
}

bool BluePrints::parseXMLFile(const std::string& xmlFilename)
{
	CCASSERT(FileUtils::getInstance()->isFileExist(xmlFilename) == true, "blueprint.xml not found.");
	SAXParser parser;

	if (false == parser.init("UTF-8"))
	{
		return false;
	}

	parser.setDelegator(this);
	return parser.parse(FileUtils::getInstance()->fullPathForFilename(xmlFilename).c_str());
}

void BluePrints::startElement(void *ctx, const char *name, const char **atts)
{
	CC_UNUSED_PARAM(ctx);
	std::string elementName = (char*)name;
	ValueMap attributeDict;
	if (atts && atts[0])
	{
		for (int i = 0; atts[i]; i += 2)
		{
			std::string key = (char*)atts[i];
			std::string value = (char*)atts[i + 1];
			attributeDict.insert(std::make_pair(key, Value(value)));
		}
	}
	if (elementName == "Blueprints")
	{

	}
	else if (elementName == "Entity")
	{
		auto blueprint = BluePrint::create();
		std::string entityType = attributeDict["type"].asString();
		blueprint->_type = entityType;
		_blueprints.pushBack(blueprint);

		DataTableManager::getInstance()->addCategory(entityType);
	}
	else if (elementName == "Components")
	{

	}
	else if (elementName == "Component")
	{
		auto blueprint = _blueprints.back();
		std::string componentName = attributeDict["name"].asString();
		blueprint->addComponent(componentName);
	}
	else
	{
		elementName += " - What the blueprint elementname?";
		CCASSERT(false, elementName.c_str());
	}
}

void BluePrints::endElement(void *ctx, const char *name)
{
	CC_UNUSED_PARAM(ctx);
}

void BluePrints::textHandler(void *ctx, const char *ch, int len)
{
	CC_UNUSED_PARAM(ctx);
}

}