#include <iostream>

#include "Stack.h "

template <class T>
void Stack<T>::push(T aData) {
	Node<T>* temp = new Node<T>();
	temp->_data = aData;
	temp->_level = _elements;

	if (_top == nullptr) {
		_top = temp;
	}
	else {
		// link top to bottom of temp
		temp->_link = _top;
		// change temp to top
		_top = temp;
	}

	_elements += 1;
}

template <class T>
void Stack<T>::pop() {
	// return and remove top
	if (_top == nullptr) {
		return;
	}
	Node<T>* temp = new Node<T>();
	// go down one
	_top = _top->_link;
	// remove top
	temp->_link = nullptr;
	// free mem
	free(temp);

	_elements -= 1;
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
		temp = temp->_link;
	}
}