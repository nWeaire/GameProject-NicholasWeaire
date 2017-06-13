#pragma once
#include "State.h"

class LoadingState : public State
{
public:
	LoadingState();
	~LoadingState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:
	float timer;
	Font* m_font;

};

