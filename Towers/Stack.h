#pragma once

#include "Node.h"

// linked list stack
template <class T>
class Stack
{
public:

	// constructor
	Stack();
	// destructor
	~Stack();
	// copy constructor
	Stack(const Stack<T>& aStack);



	void push(T aData);
	void pop();
	void printTopDown();
	void printBotUp();
	T peek();

	bool hasMore();
	bool isIn(T val);

	T getLowest();

	int _elements;
	Node<T>* _top;
	Node<T>* _bot;
};
