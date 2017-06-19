#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>
#include "Map.h"
template <typename T>
class ResourceManager
{
public:


	//----------------------------------------------------
	// Loads resource from file name and sets a font size
	// returns:
	//		T*: templated type of resource
	// params:
	//		szFilename: file name of resource
	//		Size: Font size, only used with font
	//----------------------------------------------------
	T* LoadResource(char* szFilename, int size)
	{

		//Check if resource is already loaded
		//if it is, return it
		if (m_ResourceList.IsItem(szFilename))
		{
			return m_ResourceList[szFilename]->m_pData;
		}
				
	

		//Resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFilename, size);
		m_ResourceList.AddItem(szFilename, pResource);
		return pResource->m_pData;
		
	}

	//----------------------------------------------------
	// unloads and deletes all resources
	//----------------------------------------------------
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
		
	}

	//----------------------------------------------------
	// Checks if resource manager has been created before
	// Creates Resource manager
	//----------------------------------------------------
	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new ResourceManager<T>();
	}

	//----------------------------------------------------
	// Deletes resource manager
	//----------------------------------------------------
	static void Delete()
	{
		delete m_pInstance;
	}

	//----------------------------------------------------
	// gets the instance of resource manager to call all the functions from
	// returns:
	//		ResourceManager<T>*: returns the resource manager to call functions from
	//----------------------------------------------------
	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

	// Map of resources
	Map<Resource<T>*> m_ResourceList;

	// Static instance of resource manaher
	static ResourceManager<T>* m_pInstance;


private:
	//----------------------------------------------------
	// Default constructor
	//----------------------------------------------------
	ResourceManager()
	{

	}

	//----------------------------------------------------
	// Default destructor
	// Calls UnloadAllResources()
	//----------------------------------------------------
	~ResourceManager()
	{
		UnloadAllResources();
	}
};

template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;

