#include "MenuState.h"
#include "Application2D.h"
#include "Input.h"


MenuState::MenuState()
{

}

MenuState::~MenuState()
{

}

void MenuState::OnEnter()
{
	m_font = new Font("./font/consolas.ttf", 32);
	


}

void MenuState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
		pMachine->PopState();


}

void MenuState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Press Enter to start game!", 0, 720 - 64);

}

void MenuState::OnExit()
{
	delete m_font;
}
