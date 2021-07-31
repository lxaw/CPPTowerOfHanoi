#pragma once


template <class T>
struct Node
{
	T _data;
	Node<T>* _link;
	int _level;
};

