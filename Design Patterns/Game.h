#pragma once
#include "State.h"
class Game :
	public State
{
public:
	Game();
	virtual ~Game();


	void OnEnter() = 0;
	void OnUpdate(float fDeltaTime) = 0;
//	void OnDraw(Renderer2D* m_2dRenderer) = 0;
	void OnExit() = 0;

};

