#include "basegamefeature/components/attributecomponent.h"

USING_NS_CC;

namespace BaseGameFeature
{

IMPLEMENT_CLASS_COMPONENT_INFO(AttributeComponent)

AttributeComponent::AttributeComponent()
{
}

AttributeComponent::~AttributeComponent(void)
{
	attrs.clear();
}

bool AttributeComponent::init()
{
	setName("AttributeComponent");
	return true;
}

void AttributeComponent::onEnter()
{

}

void AttributeComponent::onExit()
{
	attrs.clear();
}

void AttributeComponent::setInt(const std::string& key, int value)
{
	attrs[key] = Value(value);
}

void AttributeComponent::setFloat(const std::string& key, float value)
{
	attrs[key] = Value(value);
}

void AttributeComponent::setBool(const std::string& key, bool value)
{
	attrs[key] = Value(value);
}

void AttributeComponent::setString(const std::string& key, const std::string& value)
{
	attrs[key] = Value(value);
}

int AttributeComponent::getInt(const std::string& key, int def) const
{
	if (attrs.find(key) != attrs.end())
	{
		const Value& v = attrs.at(key);
		return v.asInt();
	}

	return def;
}

float AttributeComponent::getFloat(const std::string& key, float def) const
{
	if (attrs.find(key) != attrs.end())
	{
		const Value& v = attrs.at(key);
		return v.asFloat();
	}

	return def;
}

bool AttributeComponent::getBool(const std::string& key, bool def) const
{
	if (attrs.find(key) != attrs.end())
	{
		const Value& v = attrs.at(key);
		return v.asBool();
	}

	return def;
}

std::string AttributeComponent::getString(const std::string& key, const std::string& def) const
{
	if (attrs.find(key) != attrs.end())
	{
		const Value& v = attrs.at(key);
		return v.asString();
	}

	return def;
}

bool AttributeComponent::hasAttr(const std::string& key)
{
	if (attrs.find(key) != attrs.end())
	{
		return true;
	}
	return false;
}

}