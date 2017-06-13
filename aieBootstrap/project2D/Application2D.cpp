#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MenuState.h"
#include "GameState.h"
#include "SplashState.h"
#include "LoadingState.h"
#include "ResourceManager.h"
#include "PauseState.h"
using namespace aie;



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
	
	// Creates new state machine
	m_StateMachine = new StateMachine();

	// Creates states for game, menu, splash and loading
	m_StateMachine->AddState(0, new GameState());
	m_StateMachine->AddState(1, new MenuState());
	m_StateMachine->AddState(2, new SplashState());
	m_StateMachine->AddState(3, new LoadingState());
	m_StateMachine->AddState(4, new PauseState());
	// Adds inital states on startup of game
	m_StateMachine->PushState(0);
	m_StateMachine->PushState(1);
	m_StateMachine->PushState(2);
	m_StateMachine->PushState(3);



	// Sets basic camera variables
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	// Deletes everything to avoid memory leaks
	delete m_2dRenderer;
	CollisionManager::Destroy();
	ResourceManager<Font>::Delete();
	delete m_StateMachine;

}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// Calls update on all states
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

	// Draws states
	m_StateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}