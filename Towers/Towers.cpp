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

	for (int i = 0;i < 3;i++) {
		for (int j = i;j < 3;j++) {
			t.swap(i, j);
			t.printTowerOfHanoi();
		}
	}

}

