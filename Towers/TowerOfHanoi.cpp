#include <vector>
#include <iostream>
#include <random>

#include "TowerOfHanoi.h"
#include "Node.h"
#include "Node.cpp"

// constructor
template <class T>
TowerOfHanoi<T>::TowerOfHanoi(int lB, int uB) {
	setTowerInt(lB, uB);

	/*
	To do: throw error if negative
	*/
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


template<class T>
void TowerOfHanoi<T>::peekPopPush(Stack<T>& sFrom, Stack<T>& sTo) {
	if (sFrom.hasMore()) {
		T val = sFrom.peek();
		sFrom.pop();

		sTo.push(val);
	}
}

template <class T>
void TowerOfHanoi<T>::move(int iFrom, int iTo) {
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
}

template <class T>
bool checkLessThanStack(Stack<T>& fromStack, Stack<T>& toStack) {
	
	if (fromStack._top != nullptr && toStack._top != nullptr) {
		// can compare
		if (fromStack._top < toStack._top) {
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
	/*
	To do: move all left first
	*/
	sort(print, _numDisks, 0,2,1 );
}

template <class T>
void TowerOfHanoi<T>::sort(bool print,int numDisks, int fromI, int toI,int auxI) {
	if (numDisks > 0) {
		// move n-1 from source to aux
		sort(print,numDisks - 1, fromI, auxI, toI);
		// move nth disk from source to target
		move(fromI, toI);
		if (print) {
			this->printTowerOfHanoi();
		}
		// move n-1 on aux to target
		sort(print,numDisks - 1, auxI, toI, fromI);
	}
}





/*
Graphical version
*/
template <class T>
TowerOfHanoiGraphic<T>::TowerOfHanoiGraphic(int block_count, unsigned int win_w, unsigned int win_h) {
	_win_w = win_w;
	_win_h = win_h;
	_block_count = block_count;

	peg0 = Peg{ 0, _win_w, _win_h };
	peg1 = Peg{ 1, _win_w, _win_h };
	peg2 = Peg{ 2, _win_w, _win_h };

	_pegs = { peg0,peg1,peg2 };

	// set the stacks
	this->randomizeDisk(block_count, _block_lb, _block_ub);

	// initialize disks
	// top down
	Node<T>* l = this->_leftStack._top;
	Node<T>* m = this->_middleStack._top;
	Node<T>* r = this->_rightStack._top;

}

template <class T>
std::vector<T> TowerOfHanoiGraphic<T>::getStackVector(int stackIndex) {
	std::vector<T> retVec;
	if (stackIndex == 0) {
		Node<T>* l = this->_leftStack._top;
		while (l != nullptr) {
			retVec.push_back(l->_data);
			l = l->_prev;
		}
	}
	else if (stackIndex == 1) {
		Node<T>* m = this->_middleStack._top;
		while (m != nullptr) {
			retVec.push_back(m->_data);
			m = m->_prev;
		}
	}
	else if (stackIndex == 2) {
		Node<T>* r = this->_rightStack._top;
		while (r != nullptr) {
			retVec.push_back(r->_data);
			r = r->_prev;
		}
	}
	return retVec;
}
