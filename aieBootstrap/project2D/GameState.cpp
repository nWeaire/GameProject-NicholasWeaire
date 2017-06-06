#include "GameState.h"
#include "Application2D.h"
#include "PauseState.h"


GameState::GameState()
{
	m_font = new Font("./font/consolas.ttf", 32);
	o1 = new ObjectPool(10);
}


GameState::~GameState()
{
	delete m_font;
	delete o1;
}

void GameState::OnEnter()
{
	
}

void GameState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_P))
	{
		pMachine->AddState(4, new PauseState());
		pMachine->PushState(4);
	}
		
	if (input->isKeyDown(INPUT_KEY_1))
	{
		BoxObject* p = o1->Allocate();
	}
	o1->Update(fDeltaTime);
}

void GameState::OnDraw(Renderer2D * m_2dRenderer)
{
	o1->Draw(m_2dRenderer);
	m_2dRenderer->drawText(m_font, "Press 1 to add an object from the object pool!", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Press p to pause game!", 0, 720 - 128);
}

void GameState::OnExit()
{

}
