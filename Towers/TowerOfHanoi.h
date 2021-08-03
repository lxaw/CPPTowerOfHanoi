#pragma once

#include <vector>

#include "Stack.h"
#include "Stack.cpp"

#include "Sprites.h"

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

	void swap(int iFrom, int iTo);

	/*
	Move element from one stack to another, no swap.
	*/
	void move(int iFrom, int iTo);



	void randomizeInt(int maxElems,int lB,int uB);
	int getRandomInt(int lB, int uB);

	void sort(bool print=false);

	Stack<T> _leftStack;
	Stack<T> _middleStack;
	Stack<T> _rightStack;

	/*
	Swap the top values from two stacks
	*/
	void swapStack(Stack<T>& s0, Stack<T>& s1);
	/*
	Push val from one stack onto other
	*/
	void peekPopPush(Stack<T>& sFrom, Stack<T>& sTo);

	int getMostElements();
	T getMaxFromVector(std::vector<T> aVec);
};

template <class T>
class TowerOfHanoiGraphic : public TowerOfHanoi<T> {
public:
	TowerOfHanoiGraphic(int block_count,unsigned int win_w, unsigned int win_h);

	static const int _block_lb = 1;
	static const int _block_ub = 9;

	unsigned int _win_w;
	unsigned int _win_h;
	int _block_count;

	Peg peg0;
	Peg peg1;
	Peg peg2;

	std::vector<Peg> _pegs;

	std::vector<Disk> _leftDisks;
	std::vector<Disk> _middleDisks;
	std::vector<Disk> _rightDisks;
};

