#include "SplashState.h"
#include "Font.h"
#include "StateMachine.h"
#include "ResourceManager.h"

//-------------------------------------
// Constructor
// Gets instance of resource manager of type font
//-------------------------------------
SplashState::SplashState()
{
	timer = 0;
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}

//----------------------------------------------------
// Default destructor
//----------------------------------------------------
SplashState::~SplashState()
{
	

}

//----------------------------------------------------
// functions to run when entering state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void SplashState::OnEnter(StateMachine* pMachine)
{
	pMachine->SetBackgroundRender(false);

}

//----------------------------------------------------
// Update state when update function is called in State Machine
// params:
//		DeltaTime: to make everything in seconds
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void SplashState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	timer += fDeltaTime;

	if (timer > 3)
		pMachine->PopState();

}

//----------------------------------------------------
// Draw functions to run when draw function is called from state machine
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void SplashState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Splash Screen, Please Wait!", 0, 720 - 64);
}

//----------------------------------------------------
// functions to run when exiting state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void SplashState::OnExit(StateMachine* pMachine)
{

}
