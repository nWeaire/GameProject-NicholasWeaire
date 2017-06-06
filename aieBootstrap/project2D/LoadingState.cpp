#include "LoadingState.h"
#include "Font.h"
#include "StateMachine.h"

LoadingState::LoadingState()
{
	timer = 0;
}


LoadingState::~LoadingState()
{
}

void LoadingState::OnEnter()
{
	m_font = new Font("./font/consolas.ttf", 32);


}

void LoadingState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	timer += fDeltaTime;

	if (timer > 3)
		pMachine->PopState();
		

}

void LoadingState::OnDraw(Renderer2D * m_2dRenderer)
{

	m_2dRenderer->drawText(m_font, "Loading, Please Wait!", 0, 720 - 64);

}

void LoadingState::OnExit()
{
	delete m_font;



}
