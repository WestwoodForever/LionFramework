#pragma once

#include "core/EventCustomComponent.h"

namespace Attr
{
	const std::string Graphics = "Graphics";
}

namespace GraphicsFeature
{
	
class GraphicsComponent : public Core::EventCustomComponent
{
	DECLARE_CLASS_COMPONENT_INFO
	CREATE_FUNC(GraphicsComponent);
public:
	//CC_CONSTRUCTOR_ACCESS:
	GraphicsComponent();
	virtual ~GraphicsComponent();

	virtual bool init() override;

	virtual void onEnter() override;
	virtual void onExit() override;

protected:
	virtual void setupAttributes();
	virtual void setupEventCustom();
};

}