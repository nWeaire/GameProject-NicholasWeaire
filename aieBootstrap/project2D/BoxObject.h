#pragma once
#include "Entity.h"
class BoxObject : public Entity
{
public:

	//----------------------------------------------------
	// Sets a render colour of red and then draws a basic square
	//----------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//----------------------------------------------------
	// default constructor that sets timer variable
	//----------------------------------------------------
	BoxObject();

	//----------------------------------------------------
	// default destructor
	//----------------------------------------------------
	~BoxObject();

	//----------------------------------------------------
	// sets the object to either an active or non-active state
	// parameters:
	//	takes in a bool to determine if the object is on or off
	//----------------------------------------------------
	void SetActive(bool bActive);

	//----------------------------------------------------
	// Checks whether the object is active or not
	// returns:
	//	returns bool determining whether it is active or not
	//----------------------------------------------------
	bool GetActive();

	//----------------------------------------------------
	// updates any transformations on the object
	// parameters:
	//		takes in deltatime so everything is in seconds
	//----------------------------------------------------
	void UpdateTransforms(float fDeltaTime);


private:
	// Timer float to be used in further functions
	float timer;
};

