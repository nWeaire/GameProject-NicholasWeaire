#include "ObjectPool.h"
#include "ObjectPoolEntity.h"

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new ObjectPoolEntity*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new ObjectPoolEntity();
	}

}

ObjectPool::~ObjectPool()
{
	delete[] m_pPool;
}

ObjectPoolEntity* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->GetActive())
		{
			m_pPool[i]->SetActive(true);
			return m_pPool[i];
		}
	
	}

	return nullptr;
}

void ObjectPool::Deallocate(ObjectPoolEntity* object)
{
	object->SetActive(false);
}
