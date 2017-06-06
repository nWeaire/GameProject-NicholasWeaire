#include "SplashState.h"
#include "Font.h"
#include "StateMachine.h"


SplashState::SplashState()
{
	timer = 0;
}


SplashState::~SplashState()
{
}

void SplashState::OnEnter()
{
	m_font = new Font("./font/consolas.ttf", 32);

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
	delete m_font;
}
