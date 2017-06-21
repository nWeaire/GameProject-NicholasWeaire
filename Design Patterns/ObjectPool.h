#pragma once
#include "BoxObject.h"


class ObjectPool
{
public:

	//----------------------------------------------------
	// Default constructor
	// params:
	//		nMaxSize: Max starting size for object pool array
	//----------------------------------------------------
	ObjectPool(int nMaxSize);
	
	//----------------------------------------------------
	// Default destructor
	//----------------------------------------------------
	~ObjectPool();

	//----------------------------------------------------
	// updates transformation of objects in object pool
	// params:
	//		fDeltaTime: updates in seconds rather then frames
	//----------------------------------------------------
	void Update(float fDeltaTime);
	
	//----------------------------------------------------
	// Checks if objects are active
	// Draws objects if they're in use
	// Params:
	//		m_2dRenderer: Aie bootstraps renderer
	//----------------------------------------------------
	void Draw(aie::Renderer2D* m_2dRenderer);
	
	//----------------------------------------------------
	// cycles through array to check for non-allocated object
	// sets it to active
	// returns:
	//		BoxObject*: Returns pointer to the allocated object
	//----------------------------------------------------
	BoxObject* Allocate();
	
	//----------------------------------------------------
	// sets active to false for a certain object
	// params:
	//		BoxObject*: takes in pointer to an object to deallocate
	//----------------------------------------------------
	void Deallocate(BoxObject* object);

private:
	BoxObject** m_pPool;
	int m_nMaxSize;
	float fDeltaTime;
};