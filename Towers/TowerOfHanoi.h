// Written (with love) by Lex Whalen
#pragma once

#include <vector>

#include "Stack.h"
#include "Move.h"
#include "Sprites.h"


template <class T>
class TowerOfHanoi
{
public:
	// default constructor
	TowerOfHanoi();
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

	/*
	Past moves
	*/
	Stack<Move> _moves;
	void pushMove(int iFrom, int iTo);


	void printTowerOfHanoi();

	void swap(int iFrom, int iTo);

	/*
	Move element from one stack to another, no swap.
	*/
	void move(int iFrom, int iTo,bool addToStack);

	// check if you can move from stack iFrom to stack iTo, where iFrom and iTo are the id of stack
	// ex: can move left, middle: canMove(0,1)
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

	/*
	Reset the stack to beginning
	*/
	void reset(bool print);
private:
	// recursive sort
	void sort(bool print, int numDisks, int fromI, int toI,int auxI);
};

template <class Disk>
class TowerOfHanoiGraphic : public TowerOfHanoi<Disk> {
public:
	TowerOfHanoiGraphic(int lB, int uB,unsigned int win_w, unsigned int win_h);

	int _lB;
	int _uB;

	void setTowerDisk(Peg peg,sf::Color color);

	sf::Color _selectColor = sf::Color::Red;
	sf::Color _diskColor = sf::Color::Blue;

	sf::Font _font;
	sf::Text _text;

	void updateText();


	unsigned int _win_w;
	unsigned int _win_h;

	void moveDisk(int fromPeg, int toPeg);

	std::vector<std::string> _keys_pressed;

	bool keySizeBig();
	bool isPattern(std::string k1, std::string k2);
	void resetKeys();


	void changeTopDiskColor(int stackID,sf::Color color);
	void resetAllTopDiskColor();

	void resetDisks();

	void printKeyVec();


	sf::Color _lColor{ 255,0,0,255 };
	sf::Color _mColor{ 0,255,0,255 };
	sf::Color _rColor{ 249,255,74,255 };

	Peg _peg0;
	Peg _peg1;
	Peg _peg2;

	void sortDisks();

	std::vector<Peg> _pegs;

private:
	// recursive sort
	void sortDisks(int numDisks, int fromI, int toI,int auxI);

};

