#include "PauseState.h"
#include "Application2D.h"
#include "Input.h"
#include "ResourceManager.h"

//----------------------------------------------------
// Default constructor
//----------------------------------------------------
PauseState::PauseState()
{
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
	
}


//----------------------------------------------------
// Default destructor
//----------------------------------------------------
PauseState::~PauseState()
{
	

}

//----------------------------------------------------
// functions to run when entering state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void PauseState::OnEnter(StateMachine* pMachine)
{

	pMachine->SetBackgroundRender(true);
}

//----------------------------------------------------
// Update state when update function is called in State Machine
// params:
//		DeltaTime: to make everything in seconds
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void PauseState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
		pMachine->PopState();

	
}

//----------------------------------------------------
// Draw functions to run when draw function is called from state machine
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void PauseState::OnDraw(Renderer2D * m_2dRenderer)
{

	m_2dRenderer->drawText(m_font, "Paused, Press Enter to resume game!", 320, 400);
}

//----------------------------------------------------
// functions to run when exiting state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void PauseState::OnExit(StateMachine* pMachine)
{
	
	pMachine->SetBackgroundRender(false);
}
