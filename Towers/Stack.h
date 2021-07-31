#pragma once

#include "Node.h"

// linked list stack
template <class T>
class Stack
{
public:

	void push(T aData);
	void pop();
	void printTopDown();
	T peek();

	int _elements = 0;
	Node<T>* _top = nullptr;
};
