#include "Entity.h"


//-------------------------------------
// Default Constructor
//-------------------------------------
Entity::Entity()
{
	Parent = nullptr; // sets parent to nullptr for saftey
	float speed = 0; // sets speed
	float rotSpeed = 0; // rot speed
	float mass = 0 ; // sets mass
	m_bActive = false;
}

//-------------------------------------
// Default Destructor
//-------------------------------------
Entity::~Entity()
{
}

//-------------------------------------
// Updates Global and Local tranforms of objects for movement, rotation and Scale
//-------------------------------------
void Entity::UpdateTransforms()
{
	if (Parent) // Checks for a parent class
	{
		GlobalTransform = Parent->GlobalTransform * LocalTransform; // If there is a parent updates with parents movement
	}
	else
	{
		GlobalTransform = LocalTransform; // if no parent changes own movement, scale and rotation
	}
}

//-------------------------------------
// Sets the parent for matrix hierarchy
// Param:
//		Entity*: The object you want to set the parent as
//-------------------------------------
void Entity::SetParent(Entity * parent)
{
	Parent = parent;
}

//-------------------------------------
// Adds a Child to a dynamic array 
// Param:
//		Entity*: The object you want to set the child as
//-------------------------------------
void Entity::AddChild(Entity * child)
{
	Children.push_back(child); // Adds a child to dynamic vector
}

//-------------------------------------
// Adds a Child to a dynamic array 
// Returns:
//		Collider2D: Returns the values for the AABB 
//-------------------------------------
Collider2D Entity::getCollider()
{
	return Box;
}

void Entity::SetActive(bool bActive)
{
}

bool Entity::GetActive()
{
	return false;
}

void Entity::Draw(Renderer2D * m_2dRenderer)
{
}
