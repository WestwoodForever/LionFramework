#pragma once

#include "core\Framework.h"

namespace Core
{

class GameFramework : public Framework
{
public:
	static GameFramework* getInstance();
	static void destroyInstance();

	GameFramework();
	virtual ~GameFramework();

	virtual bool init() override;

	virtual void start() override;
	virtual void update(float delta) override;
	virtual void end() override;

protected:
	virtual void SetupFeatures() override;

private:
	static GameFramework* _sharedInstance;
};

}