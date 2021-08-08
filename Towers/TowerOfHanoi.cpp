// Written (with love) by Lex Whalen
#include <vector>
#include <iostream>
#include <random>

#include "TowerOfHanoi.h"
#include "Stack.cpp"
#include "Node.h"
#include "Move.cpp"

// default
template <class T>
TowerOfHanoi<T>::TowerOfHanoi() {
	this->_numDisks = 0;
}
// constructor
template <class T>
TowerOfHanoi<T>::TowerOfHanoi(int lB, int uB) {
	setTowerInt(lB, uB);
	this->_numDisks = uB - lB + 1;
}

// pushing
template <class T>
void TowerOfHanoi<T>::pushLeft(T aData) {
	_leftStack.push(aData);
}
template <class T>
void TowerOfHanoi<T>::pushMiddle(T aData) {
	_middleStack.push(aData);
}
template <class T>
void TowerOfHanoi<T>::pushRight(T aData) {
	_rightStack.push(aData);
}

// popping
template <class T>
void TowerOfHanoi<T>::popLeft() {
	_leftStack.pop();
}
template <class T>
void TowerOfHanoi<T>::popMiddle() {
	_middleStack.pop();
}
template <class T>
void TowerOfHanoi<T>::popRight() {
	_rightStack.pop();
}

// peeking
template <class T>
T TowerOfHanoi<T>::peekLeft() {
	return _leftStack.peek();
}
template <class T>
T TowerOfHanoi<T>::peekMiddle() {
	return _middleStack.peek();
}
template <class T>
T TowerOfHanoi<T>::peekRight() {
	return _rightStack.peek();
}

template <class T>
int TowerOfHanoi<T>::getMaxIntVec(std::vector<int> aVec) {
	int max = aVec[0];

	for (auto i : aVec) {
		if (i > max) {
			max = i;
		}
	}
	return max;
}

// print the towers
template <class T>
void TowerOfHanoi<T>::printTowerOfHanoi() {
	int lElems = _leftStack._elements;
	int mElems = _middleStack._elements;
	int rElems = _rightStack._elements;

	std::vector<int> elemVec{ lElems,mElems,rElems };
	
	int max_elem_count = getMaxIntVec(elemVec);


	if (max_elem_count == 0) {
		return;
	}

	Node<T>* l = _leftStack._top;
	Node<T>* m = _middleStack._top;
	Node<T>* r = _rightStack._top;

	std::cout << "+---------+" << "\n";
	std::cout << "| l  m  r |" << "\n";

	if (max_elem_count == _leftStack._elements) {
		while (l != nullptr) {
			// print left
			std::cout << "| " << l->_data << "  ";

			// print middle
			if (m != nullptr && m->_level == l->_level) {
				std::cout << m->_data << "  ";
				m = m -> _prev;
			}
			else {
				std::cout << "   ";
			}
			if (r != nullptr && r->_level == l->_level) {
				std::cout << r->_data << " |\n";
				r = r->_prev;
			}
			else {
				std::cout << "  |\n";
			}
			l = l->_prev;
		}
	}
	else if (max_elem_count == _middleStack._elements) {
		while (m != nullptr) {
			// print left
			if (l != nullptr && l->_level == m->_level) {
				std::cout << "| " << l->_data << "  ";
				l = l->_prev;
			}
			else {
				std::cout << "|    ";
			}
			// print m
			std::cout << m->_data << "  ";

			// print right
			if (r != nullptr && r->_level == m->_level) {
				std::cout << r->_data << " |\n";
				r = r->_prev;
			}
			else {
				std::cout << "  |\n";
			}
			
			m = m->_prev;
		}
	}
	else {

		while (r != nullptr) {
			// print left
			if (l != nullptr && l->_level == r->_level) {
				std::cout << "| "<< l->_data << "  ";
				l = l->_prev;
			}
			else {
				std::cout << "|    ";
			}
			// print mid
			if (m != nullptr && m->_level == r->_level) {
				std::cout << m->_data << "  ";
				m = m->_prev;
			}
			else {
				std::cout << "   ";
			}
			std::cout << r->_data << " |\n";

			r = r->_prev;
		}
	}
	l = nullptr;
	m = nullptr;
	r = nullptr;
	std::cout << "+---------+" << "\n";
}

template <class T>
void TowerOfHanoi<T>::swapStack(Stack<T>& stack0, Stack<T>& stack1) {
	// 0 -> 1, 1 -> 0
	T temp0 = stack0.peek();
	T temp1 = stack1.peek();
	stack0.pop();
	stack1.pop();

	stack0.push(temp1);
	stack1.push(temp0);
}


template <class T>
void TowerOfHanoi<T>::swap(int iFrom, int iTo) {
	if (iFrom == iTo) {
		return;
	}
	else if (iFrom == 0 && iTo == 1 || iFrom == 1 && iTo == 0) {
		if (_leftStack.hasMore() && _middleStack.hasMore()) {
			swapStack(_leftStack, _middleStack);
		}
		return;
	}
	else if (iFrom == 0 && iTo == 2 || iFrom == 2 && iTo == 0) {
		if (_leftStack.hasMore() && _rightStack.hasMore()) {
			swapStack(_leftStack, _rightStack);
		}
		return;
	}
	else if (iFrom == 1 && iTo == 2 || iFrom == 2 && iTo == 1) {
		if (_middleStack.hasMore() && _rightStack.hasMore()) {
			swapStack(_middleStack, _rightStack);
		}
		return;
	}
}


// used from putting a value from one stack to the other
template<class T>
void TowerOfHanoi<T>::peekPopPush(Stack<T>& sFrom, Stack<T>& sTo) {
	if (sFrom.hasMore()) {
		T val = sFrom.peek();
		sFrom.pop();

		sTo.push(val);
	}
}

template <class T>
void TowerOfHanoi<T>::pushMove(int iFrom, int iTo) {
	Move move{ iFrom, iTo };
	this->_moves.push(move);
}


// used for moving a value
// ie: move from left to right, move(0,2)
template <class T>
void TowerOfHanoi<T>::move(int iFrom, int iTo,bool addToStack) {
	if (iFrom == iTo) {
		return;
	}
	else if (iFrom == 0 && iTo == 1) {
		peekPopPush(_leftStack, _middleStack);
	}
	else if (iFrom == 0 && iTo == 2) {
		peekPopPush(_leftStack, _rightStack);
	}
	else if (iFrom == 1 && iTo == 0) {
		peekPopPush(_middleStack, _leftStack);
	}
	else if (iFrom == 1 && iTo == 2) {
		peekPopPush(_middleStack, _rightStack);
	}
	else if (iFrom == 2 && iTo == 0) {
		peekPopPush(_rightStack, _leftStack);
	}
	else if (iFrom == 2 && iTo == 1) {
		peekPopPush(_rightStack, _middleStack);
	}
	if (addToStack) {
		this->pushMove(iFrom, iTo);
	}
}

// checks if fromStack's top element smaller than toStack's top
template <class T>
bool checkLessThanStack(Stack<T>& fromStack, Stack<T>& toStack) {
	
	if (fromStack._top != nullptr && toStack._top != nullptr) {
		// can compare
		if (fromStack._top->_data < toStack._top->_data) {
			return true;
		}
		return false;
	}
	else if (fromStack._top == nullptr && toStack._top != nullptr) {
		return false;
	}
	else if (fromStack._top != nullptr && toStack._top == nullptr) {
		return true;
	}
	else {
		// both null pointer
		return false;
	}


}

template <class T>
bool TowerOfHanoi<T>::canMove(int iFrom, int iTo) {
	// can only move a smaller disk onto a bigger one
	if (iFrom == iTo) {
		return false;
	}
	else if (iFrom == 0 && iTo == 1) {
		return checkLessThanStack(this->_leftStack, this->_middleStack);
	}
	else if (iFrom == 0 && iTo == 2) {
		return checkLessThanStack(this->_leftStack, this->_rightStack);
	}
	else if (iFrom == 1 && iTo == 0) {
		return checkLessThanStack(this->_middleStack, this->_leftStack);
	}
	else if (iFrom == 1 && iTo == 2) {
		return checkLessThanStack(this->_middleStack, this->_rightStack);
	}
	else if (iFrom == 2 && iTo == 0) {
		return checkLessThanStack(this->_rightStack, this->_leftStack);
	}
	else if (iFrom == 2 && iTo == 1) {
		return checkLessThanStack(this->_rightStack, this->_middleStack);
	}
	return false;
}

template <class T>
void TowerOfHanoi<T>::setTowerInt(int lB, int uB) {
	if (lB > uB) {
		return;
	}
	// populate the left tower
	for (int i = uB; i >= lB;--i) {
		this->_leftStack.push(i);
	}
}

template <class T>
void TowerOfHanoi<T>::sort(bool print) {
	// need to move all to left peg
	sort(print, _numDisks, 0,2,1 );
	if (print) {
		std::cout << "Sorting complete.\n";
	}
}

template <class T>
void TowerOfHanoi<T>::sort(bool print,int numDisks, int fromI, int toI,int auxI) {
	if (numDisks > 0) {
		// move n-1 from source to aux
		sort(print,numDisks - 1, fromI, auxI, toI);
		// move nth disk from source to target
		move(fromI, toI,true);
		if (print) {
			std::cout << "Move disk from " << fromI << " to " << toI << "\n";
			this->printTowerOfHanoi();
		}
		// move n-1 on aux to target
		sort(print,numDisks - 1, auxI, toI, fromI);
	}
}

template <class T>
void TowerOfHanoi<T>::reset(bool print) {
	// go through the move stack, reverse the moves
	while (this->_moves.hasMore()) {
		Move t = _moves.peek();
		// swap the to and from
		int from = t._moveArr[1];
		int to = t._moveArr[0];
		// move without adding to move stack
		this->move(from, to, false);

		if (print) {
			std::cout << "Resetting towers...\n";
			this->printTowerOfHanoi();
		}
		_moves.pop();
	}
	if (print) {
		std::cout << "Towers have been reset.\n";
	}
}

/*
Graphical version
*/
template <class T>
TowerOfHanoiGraphic<T>::TowerOfHanoiGraphic(int lB, int uB, unsigned int win_w, unsigned int win_h) {
	this->_lB = lB;
	this->_uB = uB;

	this->_numDisks = uB - lB + 1;

	_win_w = win_w;
	_win_h = win_h;

	_peg0 = Peg{ 0, _win_w, _win_h };
	_peg1 = Peg{ 1, _win_w, _win_h };
	_peg2 = Peg{ 2, _win_w, _win_h };

	_pegs = { _peg0,_peg1,_peg2 };

	// load font
	_font.loadFromFile("fonts/8bitOperatorPlus8-Regular.ttf");
	_text.setFont(_font);
	updateText();
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::Black);

	this->setTowerDisk(_peg0, _diskColor);

}

template <class T>
void TowerOfHanoiGraphic<T>::setTowerDisk(Peg peg,sf::Color color) {
	// set the left tower
	for (int i = this->_uB;i >= this->_lB;--i) {
		int level = _uB - i;
		// have to push the bigger disks before the smaller
		this->_leftStack.push(Disk{ i,color,peg,level,this->_win_w,this->_win_h });
	}
}

template <class T>
void TowerOfHanoiGraphic<T>::changeTopDiskColor(int stackID,sf::Color color) {
	// select the top disk from stack, change color
	if (stackID == 0 && this->_leftStack._top != nullptr) {
		this->_leftStack._top->_data._rect.setFillColor(color);
	}
	else if (stackID == 1 && this->_middleStack._top != nullptr) {
		this->_middleStack._top->_data._rect.setFillColor(color);
	}
	else if (stackID == 2 && this->_rightStack._top != nullptr) {
		this->_rightStack._top->_data._rect.setFillColor(color);
	}
}
template <class T>
void TowerOfHanoiGraphic<T>::resetAllTopDiskColor() {
	if (this->_leftStack._top != nullptr) {
		this->_leftStack._top->_data._rect.setFillColor(this->_diskColor);
	}
	if (this->_middleStack._top != nullptr) {
		this->_middleStack._top->_data._rect.setFillColor(this->_diskColor);
	}
	if (this->_rightStack._top != nullptr) {
		this->_rightStack._top->_data._rect.setFillColor(this->_diskColor);
	}
}

template <class T>
void TowerOfHanoiGraphic<T>::moveDisk(int fromPeg, int toPeg) {
	if (fromPeg == toPeg) {
		return;
	}
	else if (fromPeg == 0 && toPeg == 1) {
		if (this->canMove(0, 1)) {
			int new_level = this->_middleStack._elements;
			// move the disk
			this->_leftStack._top->_data.changePos(this->_peg1, new_level);
			this->move(0, 1,true);
		}
	}
	else if (fromPeg == 0 && toPeg == 2) {
		if (this->canMove(0, 2)) {
			int new_level = this->_rightStack._elements;
			// move the disk
			this->_leftStack._top->_data.changePos(this->_peg2, new_level);
			this->move(0, 2,true);
		}
	}
	else if (fromPeg == 1 && toPeg == 0) {
		if (this->canMove(1, 0)) {
			int new_level = this->_leftStack._elements;
			// move the disk
			this->_middleStack._top->_data.changePos(this->_peg0, new_level);
			this->move(1,0,true);
		}
	}
	else if (fromPeg == 1 && toPeg == 2) {
		if (this->canMove(1, 2)) {
			int new_level = this->_rightStack._elements;
			// move the disk
			this->_middleStack._top->_data.changePos(this->_peg2, new_level);
			this->move(1,2,true);
		}
	}
	else if (fromPeg == 2 && toPeg == 0) {
		if (this->canMove(2, 0)) {
			int new_level = this->_leftStack._elements;
			// move the disk
			this->_rightStack._top->_data.changePos(this->_peg0, new_level);
			this->move(2,0,true);
		}
	}
	else if (fromPeg == 2 && toPeg == 1) {
		if (this->canMove(2, 1)) {
			int new_level = this->_middleStack._elements;
			// move the disk
			this->_rightStack._top->_data.changePos(this->_peg1, new_level);
			this->move(2,1,true);
		}
	}
	this->updateText();
}

template <class T>
void TowerOfHanoiGraphic<T>::updateText() {
	std::string str = "\n\n\nTotal moves: " + std::to_string(this->_moves._elements) + "\n Optimal move count: " + std::to_string(std::pow(2,(this->_numDisks))-1);
	_text.setString(str);
}

// this helps reset the keys_pressed if it gets too large
template <class T>
bool TowerOfHanoiGraphic<T>::keySizeBig() {
	if (_keys_pressed.size() >= 2) {
		return true;
	}
	return false;
}

template <class T>
void TowerOfHanoiGraphic<T>::resetKeys() {
	std::vector<std::string> new_vec;
	_keys_pressed = new_vec;
}

// this helps check if two entered keys map to some command
template <class T>
bool TowerOfHanoiGraphic<T>::isPattern(std::string k1, std::string k2) {
	if (_keys_pressed.size() != 2) {
		return false;
	}
	else if (k1 == _keys_pressed[0] && k2 == _keys_pressed[1]) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void TowerOfHanoiGraphic<T>::resetDisks() {
	while (this->_moves.hasMore()) {
		Move t = this->_moves.peek();

		int from = t._moveArr[1];
		int to = t._moveArr[0];

		moveDisk(from, to);
		this->_moves.pop();
	}
	this->updateText();
}

template <class T>
void TowerOfHanoiGraphic<T>::printKeyVec() {
	if (_keys_pressed.size() == 0) {
		return;
	}
	else {
		std::cout << "keys pressed: ";
		for (auto k : _keys_pressed) {
			std::cout << k << " ";
		}
		std::cout << "\n";
	}
}

template <class T>
void TowerOfHanoiGraphic<T>::sortDisks() {
	this->sortDisks(this->_numDisks, 0, 2, 1);

	this->updateText();
}
template <class T>
void TowerOfHanoiGraphic<T>::sortDisks(int numDisks, int fromI, int toI, int auxI) {
	if (numDisks > 0) {
		this->sortDisks(numDisks - 1, fromI, auxI, toI);
		this->moveDisk(fromI, toI);
		
		sortDisks(numDisks - 1, auxI, toI, fromI);
	}
}

