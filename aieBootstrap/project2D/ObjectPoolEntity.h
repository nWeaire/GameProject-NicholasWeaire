#pragma once
class ObjectPoolEntity
{
public:
	ObjectPoolEntity();
	~ObjectPoolEntity();

	void SetActive(bool bActive);
	bool GetActive();


private:
	bool m_bActive;
};

