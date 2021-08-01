#pragma once


template <class T>
struct Node
{
	T _data;
	Node<T>* _prev;
	int _level;

	Node<T>* _next;
};

