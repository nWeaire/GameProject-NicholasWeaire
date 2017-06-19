#pragma once
#include "LinkedList.h"
template <typename T>
class GraphNode
{
public:
	//-----------------------------------------
	// Default Constructor
	//-----------------------------------------
	GraphNode()
	{
	}

	//-----------------------------------------
	// Constructor
	// params:
	//		data: Takes in templated data for node
	//-----------------------------------------
	GraphNode(T data)
	{
		m_Data = data;
	}

	//-----------------------------------------
	// Adds a connection to another node
	// params:
	//		other: Pointer to another node
	//-----------------------------------------
	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	//-----------------------------------------
	// Removes the connection between nodes
	// params:
	//		other: pointer to another node
	//-----------------------------------------
	void RemoveConnection(GraphNode<T>* other)
	{
		m_Edges.remove(other);
	}

	// linked list of graph nodes
	LinkedList<GraphNode<T>*> m_Edges;

	// templated data to be stored in ndoes
	T m_Data;

	// Bool to check if node has be checked before
	bool m_bTraversed;
};