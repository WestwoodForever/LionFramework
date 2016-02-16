#include "DataTableManager.h"

namespace Lion
{

IMPLEMENT_SINGLETON(DataTableManager);

DataTableManager::DataTableManager()
{
	CONSTRUCT_SINGLETON;
}

DataTableManager::~DataTableManager()
{
	_categories.clear();
	_tables.clear();
	DESTRUCT_SINGLETON;
}

bool DataTableManager::init()
{
//ValueMap dict = FileUtils::getInstance()->getValueMapFromFile("Data/actor.xml");
//CCASSERT(!dict.empty(), "CCAnimationCache: File could not be found");
	//setDataTableArray(CCArray::create());

	return true;
}

void DataTableManager::onEnter()
{
	CCASSERT(_categories.size() != 0, "need categories");
}

void DataTableManager::onExit()
{

}

void DataTableManager::addCategory(const std::string& category)
{
	CCASSERT(category.empty() == false, "add category is null");
	auto it = std::find(_categories.begin(), _categories.end(), category);
	CCASSERT(it == _categories.end(), "already add category");
	_categories.push_back(category);
}

void DataTableManager::addDataTable(const std::string& category, cocos2d::ValueMap dataTable)
{

}

}
