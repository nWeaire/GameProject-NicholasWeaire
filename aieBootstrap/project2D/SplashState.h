#pragma once
#include "State.h"
class SplashState : public State
{
public:

	//----------------------------------------------------
	// Default constructor
	//----------------------------------------------------
	SplashState();

	//----------------------------------------------------
	// Default destructor
	//----------------------------------------------------
	~SplashState();

	//----------------------------------------------------
	// functions to run when entering state
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	void OnEnter(StateMachine* pMachine);

	//----------------------------------------------------
	// Update state when update function is called in State Machine
	// params:
	//		DeltaTime: to make everything in seconds
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	
	
	void OnDraw(Renderer2D* m_2dRenderer);
	
	
	void OnExit(StateMachine* pMachine);

	float timer;
	Font* m_font;

};

