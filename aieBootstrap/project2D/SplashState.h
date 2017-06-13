#pragma once
#include "State.h"
class SplashState : public State
{
public:
	SplashState();
	~SplashState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

	float timer;
	Font* m_font;

};

