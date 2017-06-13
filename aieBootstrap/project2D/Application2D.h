#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "CollisionManager.h"
#include "StateMachine.h"
#include "ObjectPool.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();


	//----------------------------------------------------
	// Creates base classes and adds states for game startup
	// returns:
	//	returns true if everything succeeds
	//----------------------------------------------------
	virtual bool startup();

	//----------------------------------------------------
	// Deletes all instances and pointers to remove possibilities of memory leaks
	//----------------------------------------------------
	virtual void shutdown();

	//----------------------------------------------------
	// Calls update on classes in game based around delta time
	//----------------------------------------------------
	virtual void update(float deltaTime);

	//----------------------------------------------------
	// Calls draw functions on classes and objects in game
	//----------------------------------------------------
	virtual void draw();

protected:

	// Creates pointers to state machine and other required bootstrap classes
	StateMachine*		m_StateMachine;
	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	// Camera and timer variables
	float m_cameraX, m_cameraY;
	float m_timer;
};