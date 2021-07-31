
#include <vector>
#include <iostream>

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

	if (max_elem_count == _leftStack._elements) {
		std::cout << "l m r" << "\n";

		while (l != nullptr) {
			// print left
			std::cout << l->_data << " ";

			// print middle
			if (m != nullptr && m->_level == l->_level) {
				std::cout << m->_data << " ";
				m = m -> _link;
			}
			else {
				std::cout << "  ";
			}
			if (r != nullptr && r->_level == l->_level) {
				std::cout << r->_data << "\n";
				r = r->_link;
			}
			else {
				std::cout << "\n";
			}
			l = l->_link;
		}
		std::cout << "\n";
	}
	else if (max_elem_count == _middleStack._elements) {
		std::cout << "l m r" << "\n";

		while (m != nullptr) {
			// print left
			if (l != nullptr && l->_level == m->_level) {
				std::cout << l->_data << " ";
				l = l->_link;
			}
			else {
				std::cout << "  ";
			}
			// print m
			std::cout << m->_data << " ";

			// print right
			if (r != nullptr && r->_level == m->_level) {
				std::cout << r->_data << "\n";
				r = r->_link;
			}
			else {
				std::cout << "\n";
			}
			
			m = m->_link;
		}
		std::cout << "\n";

	}
	else {
		std::cout << "l m r" << "\n";

		while (r != nullptr) {
			// print left
			if (l != nullptr && l->_level == r->_level) {
				std::cout << l->_data << " ";
				l = l->_link;
			}
			else {
				std::cout << "  ";
			}
			// print mid
			if (m != nullptr && m->_level == r->_level) {
				std::cout << m->_data << " ";
				m = m->_link;
			}
			else {
				std::cout << "  ";
			}
			std::cout << r->_data << "\n";

			r = r->_link;
		}
	}

	free(l);
	free(m);
	free(r);
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