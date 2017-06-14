#pragma once
#include "State.h"
#include "Input.h"
#include "Font.h"
#include "ObjectPool.h"
#include "Renderer2D.h"
class GameState : public State
{
public:
	//----------------------------------------------------
	// Default constructor
	//----------------------------------------------------
	GameState();
	
	//----------------------------------------------------
	// Default destructor
	//----------------------------------------------------
	~GameState();

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
	
	//----------------------------------------------------
	// Draw functions to run when draw function is called from state machine
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);
	
	//----------------------------------------------------
	// functions to run when exiting state
	// params:
	//		takes in the state machine so it can call from its functions
	//----------------------------------------------------
	void OnExit(StateMachine* pMachine);

private:
	// font from aie bootstrap
	Font* m_font;
	// Object pool to store squares
	ObjectPool*			o1;
	// renderer to render objects
	aie::Renderer2D*	m_2dRenderer;
};

