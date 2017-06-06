#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MenuState.h"
#include "GameState.h"
#include "SplashState.h"
#include "LoadingState.h"
#include "ResourceManager.h"
using namespace aie;


// GAME_STATE 0;
// MENU_STATE 1;
// SPLASH_STATE 2;
// LOADING_STATE 3;
// PAUSE_STATE 4;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{

	m_2dRenderer = new Renderer2D();
	
	ResourceManager<Font>::Create();

	CollisionManager::Create();
	
	m_StateMachine = new StateMachine();

	m_StateMachine->AddState(0, new GameState());
	m_StateMachine->AddState(1, new MenuState());
	m_StateMachine->AddState(2, new SplashState());
	m_StateMachine->AddState(3, new LoadingState());
	m_StateMachine->PushState(0);
	m_StateMachine->PushState(1);
	m_StateMachine->PushState(2);
	m_StateMachine->PushState(3);




	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	CollisionManager::Destroy();
	ResourceManager<Font>::Delete();
	delete m_StateMachine;

}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	m_StateMachine->Update(deltaTime);
	
	// input example
	Input* input = Input::getInstance();


}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_StateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}