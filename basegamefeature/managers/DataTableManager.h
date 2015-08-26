#pragma once

#include "base\CCValue.h"

#include "core/Manager.h"
#include "core/Singleton.h"

namespace BaseGameFeature
{

class DataTableManager : public Core::Manager
{
	DECLARE_SINGLETON(DataTableManager);
public:
	CREATE_FUNC(DataTableManager);

	DataTableManager();
	~DataTableManager();

	bool init();

	void onEnter();
	void onExit();

	void addCategory(const std::string& category);
	//template< typename T > inline T* getDataTable( unsigned int eDataTableType );
	//template< typename T > inline T* getData( unsigned int eDataTableType, int iDataIndex );

protected:
	void addDataTable(const std::string& category, cocos2d::ValueMap dataTable);

private:
	std::vector<std::string> _categories;
	cocos2d::ValueMap _tables;
};
/*
template< typename T > inline
T* DataTableManager::getDataTable( unsigned int eDataTableType )
{
#ifdef COCOS2D_DEBUG
	return dynamic_cast< T* >( getDataTableArray()->objectAtIndex( eDataTableType ) );
#else
	return static_cast< T* >( getDataTableArray()->objectAtIndex( eDataTableType ) );
#endif
}

template< typename T > inline
T* DataTableManager::getData( unsigned int eDataTableType, int iDataIndex )
{
	DataTable< T >* pDataTable = getDataTable< DataTable< T > >( eDataTableType );
#ifdef COCOS2D_DEBUG
	return dynamic_cast< T* >( pDataTable->getData( iDataIndex ) );
#else
	return static_cast< T* >( pDataTable->getData( iDataIndex ) );
#endif
}
*/
}