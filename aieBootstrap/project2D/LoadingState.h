#pragma once
#include "State.h"

class LoadingState : public State
{
public:
	LoadingState();
	~LoadingState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	float timer;
	Font* m_font;

};

