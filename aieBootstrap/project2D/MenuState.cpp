#include "MenuState.h"
#include "Application2D.h"
#include "Input.h"
<<<<<<< .mine

//----------------------------------------------------
// Default Constructor
//----------------------------------------------------
||||||| .r36


=======
#include "ResourceManager.h"
//-------------------------------------
// Default Constructor
//-------------------------------------
>>>>>>> .r40
MenuState::MenuState()
{

}

<<<<<<< .mine
//----------------------------------------------------
// Default Destructor
//----------------------------------------------------
||||||| .r36
=======
//-------------------------------------
// default Destructor
//-------------------------------------
>>>>>>> .r40
MenuState::~MenuState()
{

}

//----------------------------------------------------
// functions to run when entering state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void MenuState::OnEnter(StateMachine* pMachine)
{
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}

//----------------------------------------------------
// Update state when update function is called in State Machine
// params:
//		DeltaTime: to make everything in seconds
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void MenuState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{

	Input* input = Input::getInstance(); // Get instance for input
	if (input->wasKeyPressed(INPUT_KEY_ENTER)) // Checks if enter key was pressed
		pMachine->PopState(); // pops top state


}

//----------------------------------------------------
// Draw functions to run when draw function is called from state machine
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void MenuState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Press Enter to start game!", 0, 720 - 64); // Draws text
}

//----------------------------------------------------
// functions to run when exiting state
// params:
//		takes in the state machine so it can call from its functions
//----------------------------------------------------
void MenuState::OnExit(StateMachine* pMachine)
{
	delete m_font; // Deletes m_font to prevent memory leaks
}
