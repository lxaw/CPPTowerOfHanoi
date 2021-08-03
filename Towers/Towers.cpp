// Towers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tower of Hanoi");
	window.setFramerateLimit(60);

	sf::Vector2u size = window.getSize();
	unsigned int win_width = size.x;
	unsigned int win_height = size.y;
	TowerOfHanoiGraphic<int> t{ win_width,win_height };
	t.randomizeInt(10, 0, 5);
	t.sort(true);


	
//	sf::Event event;
//
//	while (window.isOpen()) {
//
//		while (window.pollEvent(event)) {
//			switch (event.type) {
//
//			case sf::Event::Closed:
//				window.close();
//				break;
//			}
//		}
//		// clear window
//		window.clear();
//
//
//
//		window.display();
//	}

	return 0;
}
		

