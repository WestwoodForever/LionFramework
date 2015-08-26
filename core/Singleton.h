#pragma once

#define DECLARE_SINGLETON(type) \
public: \
	static type* getInstance() \
	{ \
		CCASSERT(_instance != nullptr, "singleton instance null."); \
		return _instance; \
	} \
private: \
	static type* _instance;

#define IMPLEMENT_SINGLETON(type) \
	type* type::_instance = nullptr;

#define CONSTRUCT_SINGLETON \
	CCASSERT(_instance == 0, "singleton already init."); \
	_instance = this;

#define DESTRUCT_SINGLETON \
	CCASSERT(_instance != nullptr, "singleton not init."); \
	_instance = nullptr;
