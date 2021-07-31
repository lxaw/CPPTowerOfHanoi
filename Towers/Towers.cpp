// Towers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"

int main()
{
	TowerOfHanoi<int> t;
	for (int i = 0;i < 10;++i) {
		t.pushLeft(i);
	}
	for (int i = 0;i < 4;++i) {
		t.pushMiddle(i);
	}
	for (int i = 0;i < 8;++i) {
		t.pushRight(i);
	}

	t.printTowerOfHanoi();

	TowerOfHanoi<int> t1;

	for (int i = 0;i < 5;++i) {
		t1.pushLeft(i);
	}
	for (int i = 0;i < 12;++i) {
		t1.pushMiddle(i);
	}
	for (int i = 0;i < 7;++i) {
		t1.pushRight(i);
	}
	t1.printTowerOfHanoi();

	TowerOfHanoi<int> t2;

	for (int i = 0;i < 5;++i) {
		t2.pushLeft(i);
	}
	for (int i = 0;i < 7;++i) {
		t2.pushMiddle(i);
	}
	for (int i = 0;i < 9;++i) {
		t2.pushRight(i);
	}
	t2.printTowerOfHanoi();

}

