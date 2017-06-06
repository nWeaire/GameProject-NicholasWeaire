#include "LoadingState.h"
#include "Font.h"
#include "StateMachine.h"
#include "ResourceManager.h"
LoadingState::LoadingState()
{
	timer = 0;
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}


LoadingState::~LoadingState()
{

	delete m_font;

}

void LoadingState::OnEnter()
{

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

}
