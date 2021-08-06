


/*
Important: Node class assumes the use of a default constructor.
If there is none for a class, there will be a "deleted function" error.
*/
#pragma once

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"


std::vector<std::string> checkKeys(std::vector<std::string> key_vector) {
	if (key_vector.size() > 2) {
		std::vector<std::string> new_vec;
		return new_vec;
	}
	return key_vector;
}
bool isPattern(std::string key1, std::string key2, std::vector<std::string> key_vector) {
	if (key_vector.size() != 2) {
		return false;
	}
	if (key1 == key_vector[0] && key2 == key_vector[1]) {
		return true;
	}
	return false;
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tower of Hanoi");
	window.setFramerateLimit(60);


	sf::Vector2u size = window.getSize();
	unsigned int win_width = size.x;
	unsigned int win_height = size.y;

	Background bg{ win_width,win_height };

	TowerOfHanoiGraphic<Disk> t{1,9, win_width,win_height };
	
	sf::Event event;

	std::vector<std::string> keys_pressed;


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::EventType::KeyPressed:
				t.printTowerOfHanoi();
				if (event.key.code == sf::Keyboard::A) {
					keys_pressed.push_back("a");
					keys_pressed = checkKeys(keys_pressed);
				}
				else if (event.key.code == sf::Keyboard::S) {
					keys_pressed.push_back("s");
					keys_pressed = checkKeys(keys_pressed);
				}
				else if (event.key.code == sf::Keyboard::D) {
					keys_pressed.push_back("d");
					keys_pressed = checkKeys(keys_pressed);
				}

				if (isPattern("a", "s", keys_pressed)) {
					if (t.canMove(0, 1)) {
						t.moveDisk(0, 1);
					}
				}
				else if (isPattern("a", "d", keys_pressed)) {
					if (t.canMove(0, 2)) {
						t.moveDisk(0, 2);
					}
				}
				else if (isPattern("s", "a", keys_pressed)) {
					if (t.canMove(1, 0)) {
						t.moveDisk(1, 0);
					}
				}
				else if (isPattern("s", "d", keys_pressed)) {
					if (t.canMove(1,2)) {
						t.moveDisk(1,2);
					}
				}
				else if (isPattern("d", "a", keys_pressed)) {
					if (t.canMove(2,0)) {
						t.moveDisk(2,0);
					}
				}
				else if (isPattern("d", "s", keys_pressed)) {
					if (t.canMove(2,1)) {
						t.moveDisk(2,1);
					}
				}
				else if (event.key.code == sf::Keyboard::Escape) {
					std::vector<std::string> reset;
					keys_pressed = reset;
				}



			break;

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
		// print stacks
		Node<Disk>* l = t._leftStack._top;
		Node<Disk>* m = t._middleStack._top;
		Node<Disk>* r = t._rightStack._top;
		while (l != nullptr) {
			window.draw(l->_data._rect);
			l = l->_prev;
		}
		while (m != nullptr) {
			window.draw(m->_data._rect);
			m = m->_prev;
		}
		while (r != nullptr) {
			window.draw(r->_data._rect);
			r = r->_prev;
		}
		l = nullptr;
		m = nullptr;
		r = nullptr;


		window.display();
	}

	return 0;
}
		

