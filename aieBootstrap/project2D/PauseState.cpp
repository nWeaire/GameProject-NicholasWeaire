#include "PauseState.h"
#include "Application2D.h"
#include "Input.h"




PauseState::PauseState()
{
}


PauseState::~PauseState()
{

}

void PauseState::OnEnter()
{
	m_font = new Font("./font/consolas.ttf", 32);
}

void PauseState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
		pMachine->PopState();
}

void PauseState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Paused, Press Enter to resume game!", 0, 720 - 64);
}

void PauseState::OnExit()
{
	delete m_font;
}
