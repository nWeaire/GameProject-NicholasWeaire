#pragma once
#include "State.h"
#include "Input.h"
#include "Font.h"
#include "ObjectPool.h"
#include "Renderer2D.h"
class GameState : public State
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);

private:
	Font* m_font;
	ObjectPool*			o1;
	aie::Renderer2D*	m_2dRenderer;
};

