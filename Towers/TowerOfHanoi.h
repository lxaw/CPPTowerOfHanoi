#pragma once

#include "Stack.h"
#include "Stack.cpp"

#include <vector>

template <class T>
class TowerOfHanoi
{
public:
	void pushLeft(T aData);
	void pushMiddle(T aData);
	void pushRight(T aData);

	void popLeft();
	void popMiddle();
	void popRight();

	T peekLeft();
	T peekMiddle();
	T peekRight();


	void printTowerOfHanoi();

	// pass reference
	void swapStack(Stack<T>& s0, Stack<T>& s1);


	void swap(int iFrom, int iTo);

	void sort();

private:
	Stack<T> _leftStack;
	Stack<T> _middleStack;
	Stack<T> _rightStack;

	int getMostElements();
	T getMaxFromVector(std::vector<T> aVec);
};
