#pragma once

#include <vector>

#include "Stack.h"
#include "Stack.cpp"

#include "Sprites.h"

template <class T>
class TowerOfHanoi
{
public:
	// constructor
	TowerOfHanoi(int lB, int uB);
	
	int _numDisks;

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

	bool canMove(int iFrom, int iTo);

	void setTowerInt(int lB, int uB);



	int getMaxIntVec(std::vector<int> aVec);

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
private:
	// recursive sort
	void sort(bool print, int numDisks, int fromI, int toI,int auxI);
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

	sf::Color _lColor{ 255,0,0,255 };
	sf::Color _mColor{ 0,255,0,255 };
	sf::Color _rColor{ 249,255,74,255 };

	Peg peg0;
	Peg peg1;
	Peg peg2;

	std::vector<Peg> _pegs;

	std::vector<T> getStackVector(int stackIndex);
};

