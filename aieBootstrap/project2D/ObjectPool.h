#pragma once

class ObjectPoolEntity;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	ObjectPoolEntity* Allocate();
	void Deallocate(ObjectPoolEntity* object);

private:
	ObjectPoolEntity** m_pPool;
	int m_nMaxSize;

};