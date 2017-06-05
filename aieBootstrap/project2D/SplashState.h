#pragma once
#include "State.h"
class SplashState :
	public State
{
public:
	SplashState();
	~SplashState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

	float timer;
	aie::Font*			m_font;

};

