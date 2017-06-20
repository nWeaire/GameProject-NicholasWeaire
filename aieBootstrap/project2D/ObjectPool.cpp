#include "ObjectPool.h"

//----------------------------------------------------
// Default constructor
// params:
//		nMaxSize: Max starting size for object pool array
//----------------------------------------------------
ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize; // Sets max size for object pool array
	m_pPool = new BoxObject*[nMaxSize]; // Creates new array of entities

	for (int i = 0; i < nMaxSize; ++i) // for loop to go through all objects in the array
	{
		m_pPool[i] = new BoxObject(); // Fills array with objects
	}

}

//----------------------------------------------------
// Default destructor
//----------------------------------------------------
ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i) // goes through all objects in the array
	{
		delete m_pPool[i]; // Delete all objects in array
	}
	delete[] m_pPool; // Deletes array
}

//----------------------------------------------------
// updates transformation of objects in object pool
// params:
//		fDeltaTime: updates in seconds rather then frames
//----------------------------------------------------
void ObjectPool::Update(float fDeltaTime)
{
	for (int i = 0; i < m_nMaxSize; ++i) // goes through all objects in the array
	{
		if (m_pPool[i]->GetActive()) // checks if objects are active
		{
			m_pPool[i]->UpdateTransforms(fDeltaTime); // call update on all active objects
		}
		else
			return;
	}
}

//----------------------------------------------------
// Checks if objects are active
// Draws objects if they're in use
// Params:
//		m_2dRenderer: aie bootstraps renderer
//----------------------------------------------------
void ObjectPool::Draw(aie::Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_nMaxSize; ++i) // goes through all objects in the array
	{
		if (m_pPool[i]->GetActive()) // checks if objects are active
		{
			m_pPool[i]->Draw(m_2dRenderer); // calls draw function on all active objects
		}
		else
			return;
	}
}

//----------------------------------------------------
// cycles through array to check for non-allocated object
// sets it to active
// returns:
//		BoxObject*: Returns pointer to the allocated object
//----------------------------------------------------
BoxObject* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i) // Goes through all of the objects in the array
	{
		if (!m_pPool[i]->GetActive()) // Checks for a non active object
		{
			m_pPool[i]->SetActive(true); // sets it to active
			return m_pPool[i]; // returns the object
		}
	
	}

	return nullptr;
}

//----------------------------------------------------
// sets active to false for a certain object
// params:
//		BoxObject*: takes in pointer to an object to deallocate
//----------------------------------------------------
void ObjectPool::Deallocate(BoxObject* object)
{
	object->SetActive(false);
}
