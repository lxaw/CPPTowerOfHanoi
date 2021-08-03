#include <vector>
#include <iostream>
#include <random>

#include "TowerOfHanoi.h"
#include "Stack.h"
#include "Node.h"

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

// get max from an array
template <class T>
T TowerOfHanoi<T>::getMaxFromVector(std::vector<T> aVec) {
	T max = aVec[0];

	for (int i = 0;i < aVec.size();++i) {
		if (aVec[i] > max) {
			max = aVec[i];
		}
	}

	return max;
}

template <class T>
int TowerOfHanoi<T>::getMostElements() {
	int lElems = _leftStack._elements;
	int mElems = _middleStack._elements;
	int rElems = _rightStack._elements;

	std::vector<int> elem_vec{ lElems,mElems,rElems };

	int max_elem_count = getMaxFromVector(elem_vec);

	return max_elem_count;
}
// print the towers
template <class T>
void TowerOfHanoi<T>::printTowerOfHanoi() {
	int max_elem_count = getMostElements();

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
template <class T>
int TowerOfHanoi<T>::getRandomInt(int lB, int uB) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(lB,uB);

	return uni(rng);
}

template <class T>
void TowerOfHanoi<T>::randomizeInt(int maxElems,int lB,int uB) {

	// randomize each tower
	std::random_device rd;
	std::mt19937 rng(rd());
	
	// get a random amount of elements for each stack
	std::uniform_int_distribution<int> uni(0, maxElems);
	
	int maxElemL{ uni(rng) };
	int maxElemM{ uni(rng) };
	int maxElemR{ uni(rng) };


	// get random entries for each stack
	for (int i = 0; i < maxElemL;++i) {
		_leftStack.push(getRandomInt(lB,uB));
	}
	for (int i = 0; i < maxElemM;++i) {
		_middleStack.push(getRandomInt(lB,uB));
	}
	for (int i = 0; i < maxElemR;++i) {
		_rightStack.push(getRandomInt(lB,uB));
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
void TowerOfHanoi<T>::sort(bool print) {
	// move all but largest to right
	int counter = 0;
	while (_leftStack.hasMore()) {
		if (print) {
			std::cout << "Step: " << counter << ":\n";
			printTowerOfHanoi();
		}
		move(0, 2);
		counter++;
	}
	while (_middleStack.hasMore()) {
		if (print) {
			std::cout << "Step: " << counter << ":\n";
			printTowerOfHanoi();
		}
		move(1, 2);
		counter++;
	}

	while (_rightStack.hasMore() || _leftStack.hasMore()){
		if (_rightStack.hasMore() && _leftStack.hasMore()) {
			T rightLow{ _rightStack.getLowest() };
			T leftLow{ _leftStack.getLowest() };
			if (leftLow < rightLow) {
				// go from left
				while (_leftStack.hasMore()) {
					if (_leftStack._top->_data == leftLow) {
						move(0, 1);
					}
					else {
						move(0, 2);
					}
					if (print) {
						std::cout << "Step: " << counter << ":\n";
						printTowerOfHanoi();
					}
					counter++;
				}
			}
			else {
				// go from right
				while (_rightStack.hasMore()) {
					if (_rightStack._top->_data == rightLow) {
						move(2, 1);
					}
					else {
						move(2, 0);
					}
					if (print) {
						std::cout << "Step: " << counter << ":\n";
						printTowerOfHanoi();
					}
					counter++;
				}
			}
		}
		else if (_leftStack.hasMore()) {
			// only left stack
			T lowest = _leftStack.getLowest();
			while (_leftStack.hasMore()) {
				if (_leftStack._top->_data == lowest) {
					move(0, 1);
				}
				else {
					move(0, 2);
				}
				if (print) {
					std::cout << "Step: " << counter << ":\n";
					printTowerOfHanoi();
				}
				counter++;
			}
		}
		else {
			// only right stack
			T lowest = _rightStack.getLowest();
			while (_rightStack.hasMore()) {
				if (_rightStack._top->_data == lowest) {
					move(2,1);
				}
				else {
					move(2,0);
				}
				if (print) {
					std::cout << "Step: " << counter << ":\n";
					printTowerOfHanoi();
				}
				counter++;
			}
		}
	}

}




/*
Graphical version
*/
template <class T>
TowerOfHanoiGraphic<T>::TowerOfHanoiGraphic(int block_count,unsigned int win_w, unsigned int win_h) {
	_win_w = win_w;
	_win_h = win_h;
	_block_count = block_count;

	peg0 = Peg{ 0, _win_w, _win_h };
	peg1 = Peg{ 1, _win_w, _win_h };
	peg2 = Peg{ 2, _win_w, _win_h };

	_pegs = { peg0,peg1,peg2 };

	// set the stacks
	this->randomizeInt(block_count,_block_lb,_block_ub);

	// initialize disks
	// top down
	Node<T>* l = this->_leftStack._top;
	Node<T>* m = this->_middleStack._top;
	Node<T>* r = this->_rightStack._top;

	sf::Color lColor{ 255,0,0,255 };
	sf::Color mColor{ 0,255,0,255 };
	sf::Color rColor{ 0,0,255,255 };

	while (l != nullptr) {
		_leftDisks.push_back(Disk{ l->_data,lColor,peg0._x,l->_level,block_count,_win_w,_win_h});
		l = l->_prev;
	}
	while (m != nullptr) {
		_middleDisks.push_back(Disk{ m->_data,mColor,peg1._x,m->_level,block_count,_win_w,_win_h });
		m = m->_prev;
	}
	while (r != nullptr) {
		_rightDisks.push_back(Disk{ r->_data,rColor,peg2._x,r->_level,block_count,_win_w,_win_h});
		r = r->_prev;
	}


	
}
