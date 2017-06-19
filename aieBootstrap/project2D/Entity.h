#pragma once
#include <vector>
#include "Matrix3.h"
#include "Collider2D.h"
#include "Renderer2D.h"

using namespace aie;
//-------------------------------------
// Parent class which all objects will be derived from
//-------------------------------------
class Entity
{
public:
	//-------------------------------------
	// Default Constructor
	//-------------------------------------
	Entity();
	
	//-------------------------------------
	// Default Destructor
	//-------------------------------------
	~Entity();

	//-------------------------------------
	// Updates Global and Local tranforms of objects for movement, rotation and Scale
	//-------------------------------------
	void UpdateTransforms();

	//-------------------------------------
	// Sets the parent for matrix hierarchy
	// Param:
	//		Entity*: The object you want to set the parent as
	//-------------------------------------
	void SetParent(Entity* parent);
	
	//-------------------------------------
	// Adds a Child to a dynamic array 
	// Param:
	//		Entity*: The object you want to set the child as
	//-------------------------------------
	void AddChild(Entity* child);

	//-------------------------------------
	// Adds a Child to a dynamic array 
	// Returns:
	//		Collider2D: Returns the values for the AABB 
	//-------------------------------------
	Collider2D getCollider();

	// Dynamic array for Children to be set in the AddChild function
	std::vector<Entity*> Children;
	
	// Entity* for parents
	Entity* Parent;
	
	// Local transform for update functions for Movement, scale and rotation
	Matrix3 LocalTransform;
	// Global transform for update functions for Movement, scale and rotation
	Matrix3 GlobalTransform;

	//-------------------------------------
	// Sets active state for object
	// param:
	//		bActive: true or false for active state
	//-------------------------------------
	void Entity::SetActive(bool bActive);
	
	//-------------------------------------
	// checks whether active or not and returns bool
	// Returns:
	//		returns a bool of active state
	//-------------------------------------
	bool Entity::GetActive();

	//-------------------------------------
	// Draws Objects
	// Params:
	//		m_2dRenderer for use renderering objects
	//-------------------------------------
	void Draw(Renderer2D* m_2dRenderer);



protected:
	// Float for speed value
	float speed;
	// Vector2 for Velocity
	Vector2 velocity;
	// Float for Rotation speed
	float rotSpeed;
	// Float for mass to be set in contructor
	float mass;
	// Collider2D for value of the AABB
	Collider2D Box;

	bool m_bActive;

};

