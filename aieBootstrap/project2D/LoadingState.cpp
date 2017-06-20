#include "LoadingState.h"
#include "Font.h"
#include "StateMachine.h"
#include "ResourceManager.h"

//-------------------------------------
// Constructor
// gets instance of resource manager of type font
//-------------------------------------
LoadingState::LoadingState()
{
	// Timer for use in update
	timer = 0;

	// Gets instance of resource manager
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	
	// loads font from resource manager
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}

//-------------------------------------
// Destructor
// Deletes m_font to prevent memory leaks
//-------------------------------------
LoadingState::~LoadingState()
{
	delete m_font;
}

//----------------------------------------------------
// functions to run when entering state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void LoadingState::OnEnter(StateMachine* pMachine)
{
	// makes sure that the state under loading isn't rendered aswell
	pMachine->SetBackgroundRender(false);
}

//----------------------------------------------------
// Update state when update function is called in State Machine
// params:
//		DeltaTime: to make everything in seconds
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void LoadingState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	// updates timer
	timer += fDeltaTime;

	// checks if timer is greater than 3
	if (timer > 3)
		pMachine->PopState(); // Pops loading state off stack
}

//----------------------------------------------------
// Draw functions to run when draw function is called from state machine
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void LoadingState::OnDraw(Renderer2D * m_2dRenderer)
{
	// Draws text
	m_2dRenderer->drawText(m_font, "Loading, Please Wait!", 0, 720 - 64);

}

//----------------------------------------------------
// functions to run when exiting state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void LoadingState::OnExit(StateMachine* pMachine)
{

}
