#pragma once
#include "BoxObject.h"


class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);
	BoxObject* Allocate();
	void Deallocate(BoxObject* object);

private:
	BoxObject** m_pPool;
	int m_nMaxSize;
	float fDeltaTime;
};