#include "ObjectPoolEntity.h"



ObjectPoolEntity::ObjectPoolEntity()
{
	m_bActive = false;

}


ObjectPoolEntity::~ObjectPoolEntity()
{
}

void ObjectPoolEntity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool ObjectPoolEntity::GetActive()
{
	return m_bActive;
}