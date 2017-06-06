#include "PauseState.h"
#include "Application2D.h"
#include "Input.h"
#include "ResourceManager.h"



PauseState::PauseState()
{
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}


PauseState::~PauseState()
{
	delete m_font;

}

void PauseState::OnEnter()
{
	
}

void PauseState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
		pMachine->PopState();

	
}

void PauseState::OnDraw(Renderer2D * m_2dRenderer)
{

	m_2dRenderer->drawText(m_font, "Paused, Press Enter to resume game!", 320, 400);
}

void PauseState::OnExit()
{

}
