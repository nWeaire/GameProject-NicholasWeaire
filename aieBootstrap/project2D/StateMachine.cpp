#include "StateMachine.h"

StateMachine* StateMachine::m_instance = nullptr;

//-------------------------------------
// Returns the collision manager for use in classes  
// Returns:
//		CollisionManager: to allow other objects to use collison manager
//-------------------------------------
StateMachine* StateMachine::GetInstance()
{
	return m_instance;
}

//-------------------------------------
// Creates new collision manager and checks theres only one 
//-------------------------------------
void StateMachine::Create()
{
	if (!m_instance)
	{
		m_instance = new StateMachine();
	}
}

//-------------------------------------
// Deletes collision manager
//-------------------------------------
void StateMachine::Destroy()
{
	delete m_instance;
}

void StateMachine::Update(float fDeltaTime)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->OnUpdate(fDeltaTime);
}

void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->OnDraw(m_2dRenderer);
}

void StateMachine::SetState(int nStateIndex)
{
	if (m_nCurrentState >= 0)
		m_StateList[m_nCurrentState]->OnExit();

	m_nCurrentState = nStateIndex;

	m_StateList[m_nCurrentState]->OnEnter();

}

void StateMachine::AddState(int nStateIndex, State * pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

