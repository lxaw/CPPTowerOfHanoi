// Towers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"

int main()
{
	TowerOfHanoi<int> t;
	t.randomizeInt(5, 0, 5);
	t.printTowerOfHanoi();


}

