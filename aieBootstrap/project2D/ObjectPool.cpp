#include "ObjectPool.h"


ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new BoxObject*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new BoxObject();
	}

}

ObjectPool::~ObjectPool()
{
	delete[] m_pPool;
}

void ObjectPool::Update(float fDeltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->UpdateTransforms(fDeltaTime);
		}
		else
			return;
	}
}

void ObjectPool::Draw(aie::Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Draw(m_2dRenderer);
		}
		else
			return;
	}
}


BoxObject* ObjectPool::Allocate()
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

void ObjectPool::Deallocate(BoxObject* object)
{
	object->SetActive(false);
}
