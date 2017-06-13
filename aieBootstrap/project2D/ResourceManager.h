#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>
#include "Map.h"
template <typename T>
class ResourceManager
{
public:

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

	//Delete everything
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
		
	}

	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new ResourceManager<T>();
	}

	static void Delete()
	{
		delete m_pInstance;
	}

	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

	Map<Resource<T>*> m_ResourceList;

	static ResourceManager<T>* m_pInstance;


private:
	ResourceManager()
	{

	}

	~ResourceManager()
	{
		UnloadAllResources();
	}
};

template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;

