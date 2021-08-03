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



	TowerOfHanoiGraphic<int> t{10, win_width,win_height };
	t.printTowerOfHanoi();
	
	sf::Event event;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		// clear window
		window.clear();


		// draw background

		// print pegs
		for (auto peg : t._pegs) {
			window.draw(peg._rect);
		}
		// print disks
		for (auto disk : t._leftDisks) {
			window.draw(disk._rect);
		}
		for (auto disk : t._middleDisks) {
			window.draw(disk._rect);
		}
		for (auto disk : t._rightDisks) {
			window.draw(disk._rect);
		}



		window.display();
	}

	return 0;
}
		

