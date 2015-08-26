#pragma once

#include "2d/CCComponent.h"
#include "base/CCValue.h"
#include "editor-support\cocostudio\CCComBase.h"

namespace BaseGameFeature
{

class AttributeComponent : public cocos2d::Component
{
	DECLARE_CLASS_COMPONENT_INFO
	CREATE_FUNC(AttributeComponent);

public:
	AttributeComponent();
	~AttributeComponent();

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void onExit() override;

	void setInt(const std::string& key, int value);
	void setFloat(const std::string& key, float value);
	void setBool(const std::string& key, bool value);
	void setString(const std::string& key, const std::string& value);
	int getInt(const std::string& key, int def = 0) const;
	float getFloat(const std::string& key, float def = 0.0f) const;
	bool getBool(const std::string& key, bool def = false) const;
	std::string getString(const std::string& key, const std::string& def = "") const;

	bool hasAttr(const std::string& key);
	
private:
	cocos2d::ValueMap attrs;
};

}