#include "BoxObject.h"


//----------------------------------------------------
// Sets a render colour of red and then draws a basic square
//----------------------------------------------------
void BoxObject::Draw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, timer);

}

//----------------------------------------------------
// default constructor that sets timer variable
//----------------------------------------------------
BoxObject::BoxObject()
{
	timer = 0;
}

//----------------------------------------------------
// default destructor
//----------------------------------------------------
BoxObject::~BoxObject()
{
}

//----------------------------------------------------
// sets the object to either an active or non-active state
// parameters:
//	takes in a bool to determine if the object is on or off
//----------------------------------------------------
void BoxObject::SetActive(bool bActive)
{
	m_bActive = bActive;
}

//----------------------------------------------------
// Checks whether the object is active or not
// returns:
//	returns bool determining whether it is active or not
//----------------------------------------------------
bool BoxObject::GetActive()
{
	return m_bActive;
}

//----------------------------------------------------
// updates any transformations on the object
// parameters:
//		takes in deltatime so everything is in seconds
//----------------------------------------------------
void BoxObject::UpdateTransforms(float fDeltaTime)
{
	timer += fDeltaTime;



}


