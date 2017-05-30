#include <iostream>
#include "DynamicArray.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"


using namespace std;

void DynamicArrayTest() // Testing Dynamic array
{
//	DynamicArray<int> data(10);
	cout << "Dynamic Array Test!" << endl;
	DynamicArray<int> myArray(3);

	cout << "Initial sizes" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;
	
	cout << "Adding 5 initial values" << endl;
	myArray.pushBack(9);
	myArray.pushBack(8);
	myArray.pushBack(7);
	myArray.pushBack(6);
	myArray.pushBack(5);
	cout << endl;

	cout << "The new sizes are:" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;

	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	cout << endl;
	// Clears array
	myArray.Clear();
	cout << "Clearing array!" << endl;
	cout << endl;

	cout << "Adding 5 new values!" << endl;
	
	myArray.pushFront(1);
	myArray.pushFront(2);
	myArray.pushFront(3);
	myArray.pushFront(4);
	myArray.pushFront(5);
	cout << endl;

	// Prints values
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}
	cout << endl;
	cout << "Adding the number 4 in the slot 1!" << endl;
	// Inserts a 4 in slot 1
	myArray.Insert(1, 4);
	// Prints values
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}
	cout << endl;
	cout << "Removing number from slot 5" << endl;
	myArray.Remove(5);
	// Prints values
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}
	cout << endl;

	// Clear
	myArray.Clear();
	// Shrink
	myArray.Shrink();
	cout << "Clears and Shrinks!" << endl << endl;
	cout << "The new sizes are:" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;

	
}

void LinkedListTest()
{
	cout << endl;
	cout << "Linked List Test!" << endl;
	cout << endl;
	cout << "Creating Linked List" << endl;
	LinkedList<int>* l1;
	l1 = new LinkedList<int>;
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushBack(12);
	l1->IndexInsert(2, 11);
	//Print List
	cout << endl;
	cout << "Printing list" << endl;
	l1->printList();
	cout << endl;
	cout << "Removing all 10's from linked list" << endl;
	// test remove
	l1->remove(10);
	cout << endl;
	cout << "Printing First value" << endl;
	cout << l1->First() << endl;
	cout << endl;
	// test removing from iterator
	cout << "Erasing the first number" << endl;
	l1->erase(1);
	cout << l1->First() << endl;
	cout << endl;
	cout << "Clearing the entire list" << endl;
	cout << endl;
	// clears entire list
	l1->clear();
	cout << "Checking if list is empty" << endl;
	cout << endl;
	// checks if empty
	if (l1->empty() != 0)
		cout << "This list is empty!" << endl;
	else
		cout << "This list has something in it!" << endl;
	cout << endl;
	cout << "Adding 4 values to front of list" << endl;
	cout << endl;
	// Add to front and back of list
	l1->PushFront(3);
	l1->PushFront(2);
	l1->PushFront(1);
	l1->PushBack(4);

	cout << "Popping 2 values off the front of the list" << endl;
	// pop from front
	cout << l1->popFront() << endl;
	cout << l1->popFront() << endl;
	cout << endl;
	cout << "Popping 2 values off the back of the list" << endl;
	// pop from back
	cout << l1->popBack() << endl;
	cout << l1->popBack() << endl;
	cout << endl;



}

void ResourceManagerTest()
{
	// Declare in header
	// ResourceManager<aie::Texture>* m_pResourceMan; 

	// Create
	// m_pResourceMan = new ResourceManager<Texture>()
	
	// Delete
	// delete m_pResourceMan

	//m_shipTexure = m_pResourceMan->LoadResource(Texture location);
	//Texture* Ship2 = m_pResourceMan->LoadResource(Texture location);



	//singleton 
	//ResourceManager<Texture>::Create();
	//m_pResourceMan = ResourceManager<Texture>::GetInstance();

}

void QueueTest()
{

	cout << "Queue Test!" << endl;
	cout << endl;

	Queue<int>* q1;
	q1 = new Queue<int>;

	cout << "Adding 5 initial values to back of queue" << endl;
	//Create inital queue values
	q1->Push(1);
	q1->Push(2);
	q1->Push(3);
	q1->Push(4);
	q1->Push(5);

	cout << endl;
	cout << "Initial Values:" << endl;
	//Print values
	q1->printList();

	cout << endl;
	cout << "Clearing Queue" << endl;
	// Clear Queue
	q1->clear();

	cout << endl;

	cout << "Checking if empty" << endl;
	cout << endl;
	// Check if empty
	if (q1->empty() != 0)
		cout << "List is empty" << endl;
	else
		cout << "List is not empty" << endl;

	cout << endl;
	cout << "Adding another 3 values!" << endl;
	q1->Push(1);
	q1->Push(2);
	q1->Push(3);

	cout << endl;
	cout << "Pop values off and checking error checking for popping of more values then there are in the queue" << endl;
	//Popping values off
	cout << q1->pop() << endl;
	cout << q1->pop() << endl;
	cout << q1->pop() << endl;
	cout << q1->pop() << endl;
	
	cout << endl;
	cout << "End size of Queue" << endl;
	cout << q1->size() << endl;
	cout << endl;

}

void StackTest()
{

	cout << "Stack Test!" << endl;
	cout << endl;

	Stack<int>* s1;
	s1 = new Stack<int>;

	cout << "Creating Stack and added 4 values 1->4" << endl;
	s1->push(1);
	s1->push(2);
	s1->push(3);
	s1->push(4);

	cout << endl;
	cout << "Printing size of stack" << endl;
	cout << s1->size() << endl;

	cout << endl;
	cout << "Popping top value" << endl;
	cout << s1->pop() << endl;
	cout << endl;
	cout << "Printing top value" << endl;
	cout << s1->top() << endl;

	cout << endl;
	cout << "Clearing stack" << endl;
	s1->Clear();

	cout << endl;
	cout << "Checking if stack is empty" << endl;
	if (s1->empty() == true)
		cout << "Stack is empty!" << endl;
	else
		cout << "Stack is not empty!" << endl;

	cout << endl;
}

void main()
{
	//ObjectPool pool(50);

	//Entity* p = pool.Allocate();

	//pool.Deallocate(p);

	DynamicArrayTest();
	LinkedListTest();
	QueueTest();
	StackTest();

	system("pause");

}
