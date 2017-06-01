#pragma once
#include "DynamicArray.h"
#include "State.h"


class StateMachine
{
public:


	StateMachine * GetInstance();

	static void Create();

	static void Destroy();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void SetState(int nStateIndex);
	void AddState(int nStateIndex, State* pState);

private:
	
	int m_nCurrentState = -1;
	
	DynamicArray<State*> m_StateList;

	static StateMachine* m_instance;

	StateMachine();
	~StateMachine();

};

