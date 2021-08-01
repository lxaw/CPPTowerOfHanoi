#include <iostream>

#include "Stack.h "

// constructor
template <class T>
Stack<T>::Stack() {
	_top = nullptr;
	_bot = nullptr;
	_elements = 0;
}

// destructor
template<class T>
Stack<T>::~Stack() {
	Node<T>* temp = _top;
	while (temp != nullptr) {
		temp = temp->_prev;
		delete(temp);
		temp = nullptr;
	}
}
// copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& s1) {
	// pop it all
	while (hasMore()) {
		pop();
	}
	// populate the stack
	Node<T>* temp = s1._bot;
	while (temp != nullptr) {
		push(temp->_data);
		temp = temp->_next;
	}
}

template <class T>
void Stack<T>::push(T aData) {
	Node<T>* temp = new Node<T>();
	temp->_next = nullptr;
	temp->_prev = nullptr;
	temp->_data = aData;
	temp->_level = _elements;

	if (_bot == nullptr) {
		_top = temp;
		_bot = _top;
	}
	else {
		// make current last node point to new node
		_top->_next = temp;
		// make new node point to previous node
		temp->_prev = _top;
		// change temp to top
		_top = temp;
	}

	_elements ++;
}

template <class T>
void Stack<T>::pop() {
	if (_bot->_next == nullptr) {
		delete _bot;
		_bot = nullptr;
		_top = nullptr;

		_elements--;
	}
	else if (_bot != nullptr) {
		_top = _top->_prev;
		delete _top->_next;
		_top->_next = nullptr;

		_elements--;
	}
}
template <class T>
T Stack<T>::peek() {
	//return the top element
	// should call with "hasMore"
	return _top->_data;
}

template <class T>
bool Stack<T>::hasMore() {
	if (_top != nullptr) {
		return true;
	}
	return false;
}


template <class T>
void Stack<T>::printTopDown() {
	// from the top
	if (_top == nullptr) {
		return;
	}
	Node<T>* temp = _top;
	while (temp != nullptr) {
		std::cout << temp->_data << "\n";
		temp = temp->_prev;
	}
}

template<class T>
void Stack<T>::printBotUp() {
	if (_bot == nullptr) {
		return;
	}
	Node<T>* temp = _bot;
	while (temp != nullptr) {
		std::cout << temp->_data << "\n";
		temp = temp->_next;
	}

}

template <class T>
T Stack<T>::getLowest() {
	Node<T>* temp = _top;
	T lowest = temp->_data;
	while (temp != nullptr) {
		if (temp->_data < lowest) {
			lowest = temp->_data;
		}
		temp = temp->_prev;
	}

	return lowest;
}

template <class T>
bool Stack<T>::isIn(T val) {
	Node<T>* temp = _top;
	while (temp != nullptr) {
		if (temp->_data == val) {
			return true;
		}
		temp = temp->_prev;
	}

	return false;
}