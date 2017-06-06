#pragma once
#include "Entity.h"
class BoxObject : public Entity
{
public:


	void Draw(Renderer2D* m_2dRenderer);
	BoxObject();
	~BoxObject();
	void SetActive(bool bActive);
	bool GetActive();
	void UpdateTransforms(float fDeltaTime);


private:
	float timer;
};

