#pragma once
#include <vector>
#include "Entity.h"
#include "Vector2.h"
class CollisionManager
{

public:
	//-------------------------------------
	// Returns the collision manager for use in classes  
	// Returns:
	//		CollisionManager: to allow other objects to use collison manager
	//-------------------------------------
	static 	CollisionManager* GetInstance();
	
	//-------------------------------------
	// Creates new collision manager and checks theres only one 
	//-------------------------------------
	static void Create();
	
	//-------------------------------------
	// Deletes collision manager
	//-------------------------------------
	static void Destroy();
	
	//-------------------------------------
	// Adds objects to collisoin manager in a dynamic vector
	// Param:
	//		Entity*: object that requires collision
	//-------------------------------------
	void AddObject(Entity* object);

	//-------------------------------------
	// checks if there is collison between inputed object and all other objects
	// Param:
	//		Entity*: object that wants to check collision agaisnt all other objects
	// Returns:
	//		Entity*: Object that has been collided with
	//-------------------------------------
	Entity* testCollision(Entity* obj);

private:
	//-------------------------------------
	// Default Constructor
	//-------------------------------------
	CollisionManager();

	//-------------------------------------
	// Default Destructor
	//-------------------------------------
	~CollisionManager();
	
	// Static instance for Collison manager
	static CollisionManager* m_instance;
	
	// Dynamic array of all objects added through the AddObject fucntion
	std::vector<Entity*> Objects;
};

