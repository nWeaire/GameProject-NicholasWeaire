#pragma once
#include "State.h"
class GameState :
	public State
{
public:
	GameState();
	~GameState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();

};

