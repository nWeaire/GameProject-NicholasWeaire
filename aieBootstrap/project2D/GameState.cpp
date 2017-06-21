#include "GameState.h"
#include "Application2D.h"
#include "PauseState.h"
#include "ResourceManager.h"


//-------------------------------------
// Constructor
// gets instance of resource manager of type font
// creates object pool
//-------------------------------------
GameState::GameState()
{
	// Gets instance of resource manager
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
	
	//m_font = new Font("./font/consolas.ttf", 32);
	o1 = new ObjectPool(10);
	_ASSERT(o1);
}

//-------------------------------------
// Destructor
// Deletes m_font and o1 to prevent memory leaks
//-------------------------------------
GameState::~GameState()
{
	delete o1;
}

//----------------------------------------------------
// functions to run when entering state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void GameState::OnEnter(StateMachine * pMachine)
{
	pMachine->SetBackgroundRender(false);
}

//----------------------------------------------------
// Update state when update function is called in State Machine
// params:
//		DeltaTime: to make everything in seconds
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void GameState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	// gets instance of input*
	Input* input = Input::getInstance();

	// Checks for key press
	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		
		pMachine->PushState(4); //Pushes pause state on top of stack
	}
	// Checks for key press	
	if (input->wasKeyPressed(INPUT_KEY_1))
	{
		BoxObject* p = o1->Allocate(); // Allocates an object from object pool
	}
	// Update from object pool
	o1->Update(fDeltaTime);
}

//----------------------------------------------------
// Draw functions to run when draw function is called from state machine
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void GameState::OnDraw(Renderer2D * m_2dRenderer)
{
	// Draw function from object pool
	o1->Draw(m_2dRenderer);

	// Prints text on screen
	m_2dRenderer->drawText(m_font, "Press 1 to add an object from the object pool!", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Press p to pause game!", 0, 720 - 128);
}

//----------------------------------------------------
// functions to run when exiting state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void GameState::OnExit(StateMachine * pMachine)
{

}
