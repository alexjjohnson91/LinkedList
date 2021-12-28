Linked List Implementation

This is my own implementation of a Linked List template class. This is just to be a learning experience for me. I want to refresh myself on Object-Oriented Programming and Data Structures. This is knowledge that I want to learn and know and remember for whatever might come across my path. 

Members: (protected)
- Node
	- this is a layer of abstraction used in the list 
	- an abstract data type that contains two elements 
		- a value of template type T
		- a pointer to the next node in the list
- Head
	- this is a pointer to the first node in the list 

Methods: (Private)
- copy 
	- used to copy the elements of the parameter to the current list
	- can also be used in the copy constructor and the overloaded operator constructor

Methods: (Public)
- Constructor
	- default constructor of the class
- Copy Constructor/Overloaded = operator
	- copy constructor for the class 
- Destructor
	- destructor for the class. used to maintain memory
- Append
	- insert node at the end of the linked list
	- return type: void
- Insert
	- insert node at given position in the linked list
	- return type: void
- Remove 
	- remove the element at the given position in the linked list
	- return type: void
- Replace
	- replace the element at the given position in the list 
	- return type: void
- GetLength
	- return the current length of the list 
	- return type: unsigned
- isEmpty
	- determine if the list is currently empty
	- return type: bool
- Clear 
	- clears all the nodes of the list
	- return type: void
- GetElement
	- returns the value of the node at the given position
	- return type: typename T