#include "CollisionManager.h"

#include <iostream>
// Sets collionmanager to null for saftey reasons
CollisionManager* CollisionManager::m_instance = nullptr;


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

//-------------------------------------
// Returns the collision manager for use in classes  
// Returns:
//		CollisionManager: to allow other objects to use collison manager
//-------------------------------------
CollisionManager* CollisionManager::GetInstance()
{
	return m_instance;
}

//-------------------------------------
// Creates new collision manager and checks theres only one 
//-------------------------------------
void CollisionManager::Create()
{
	if(!m_instance)
		m_instance = new CollisionManager();
}

//-------------------------------------
// Deletes collision manager
//-------------------------------------
void CollisionManager::Destroy()
{
	delete m_instance;
}

//-------------------------------------
// Adds objects to collisoin manager in a dynamic vector
// Param:
//		Entity*: object that requires collision
//-------------------------------------
void CollisionManager::AddObject(Entity* object)
{
		Objects.push_back(object);
}

//-------------------------------------
// checks if there is collison between inputed object and all other objects
// Param:
//		Entity*: object that wants to check collision agaisnt all other objects
// Returns:
//		Entity*: Object that has been collided with
//-------------------------------------
Entity* CollisionManager::testCollision(Entity * obj)
{
	//For loop: through all entities in "Objects"
		//Get obj's collider and position
		//Get each Objects[i]'s collider and position
	for (int i = 0; i < Objects.size(); ++i)
	{
		if (obj == Objects[i]) // Checks if object is checking against itself
		{
			continue;
		}
		Collider2D O1 = obj->getCollider(); // Gets collider for the object
		Vector2 TR1 = O1.getTR() + obj->GlobalTransform.getPosition(); // getting position for AABB
		Vector2 BL1 = O1.getBL() + obj->GlobalTransform.getPosition(); // getting position for AABB
		Collider2D O2 = Objects[i]->getCollider(); // Gets collider for object
		Vector2 TR2 = O2.getTR() + Objects[i]->GlobalTransform.getPosition(); // getting position for AABB
		Vector2 BL2 = O2.getBL() + Objects[i]->GlobalTransform.getPosition(); // getting position for AABB
		
		//Do AABB box collision test
		if (TR1.x > BL2.x && TR1.y > BL2.y && BL1.x < TR2.x && BL1.y < TR2.y)
		{
			return Objects[i];
		}
	}
		
	return nullptr;
}
