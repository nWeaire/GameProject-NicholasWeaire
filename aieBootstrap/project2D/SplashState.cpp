#include "SplashState.h"
#include "Font.h"
#include "StateMachine.h"
#include "ResourceManager.h"

SplashState::SplashState()
{
	timer = 0;
	ResourceManager<Font>* r1 = ResourceManager<Font>::GetInstance();
	m_font = r1->LoadResource("./font/consolas.ttf", 32);
}


SplashState::~SplashState()
{
	delete m_font;

}

void SplashState::OnEnter()
{
	

}

void SplashState::OnUpdate(float fDeltaTime, StateMachine * pMachine)
{
	timer += fDeltaTime;

	if (timer > 3)
		pMachine->PopState();

}

void SplashState::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "Splash Screen, Please Wait!", 0, 720 - 64);
}

void SplashState::OnExit()
{

}
