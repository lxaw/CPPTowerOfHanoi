// Written (with love) by Lex Whalen
#pragma once


template <class T>
struct Node
{
	T _data;
	Node<T>* _prev = nullptr;
	int _level = 0;

	Node<T>* _next = nullptr;
};

