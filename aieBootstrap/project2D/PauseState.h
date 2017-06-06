#pragma once
#include "State.h"
#include "Font.h"


class PauseState : public State
{
public:
	PauseState();
	~PauseState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

private:
	aie::Font*			m_font;
};

