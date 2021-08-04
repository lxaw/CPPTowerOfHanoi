


/*
Important: Node class assumes the use of a default constructor.
If there is none for a class, there will be a "deleted function" error.
*/
#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"

int main()
{
//	TowerOfHanoi<int> t{ 1,3 };
//	t.sort(true);
//	t.reset(true);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tower of Hanoi");
	window.setFramerateLimit(60);


	sf::Vector2u size = window.getSize();
	unsigned int win_width = size.x;
	unsigned int win_height = size.y;

	Background bg{ win_width,win_height };

	TowerOfHanoiGraphic<Disk> t{1,9, win_width,win_height };
	t.printTowerOfHanoi();
	
	sf::Event event;

	std::vector<Disk> leftDisks = t.getStackVector(0);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::EventType::KeyPressed:
				t.printTowerOfHanoi();
				if (event.key.code == sf::Keyboard::Space) {
					t.move(0, 1,true);

					leftDisks = t.getStackVector(0);

					break;
				}

			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		// clear window
		window.clear();


		// draw background
		window.draw(bg._rect);

		// print pegs
		for (auto peg : t._pegs) {
			window.draw(peg._rect);
		}
		// print disks
		for (auto disk : leftDisks) {
			window.draw(disk._rect);
		}



		window.display();
	}

	return 0;
}
		

