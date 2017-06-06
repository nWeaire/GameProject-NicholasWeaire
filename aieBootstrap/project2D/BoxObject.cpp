#include "BoxObject.h"



void BoxObject::Draw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, timer);

}

BoxObject::BoxObject()
{
	timer = 0;
}


BoxObject::~BoxObject()
{
}

void BoxObject::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool BoxObject::GetActive()
{
	return m_bActive;
}

void BoxObject::UpdateTransforms(float fDeltaTime)
{
	timer += fDeltaTime;



}


