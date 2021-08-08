// Written (with love) by Lex Whalen


/*
Important: Node class assumes the use of a default constructor.
If there is none for a class, there will be a "deleted function" error.
*/
#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#include "TowerOfHanoi.h"
#include "TowerOfHanoi.cpp"



int main()
{
	sf::SoundBuffer buffer;
	// shuffle sound
	buffer.loadFromFile("audio/Electric-Transition-Super-Quick-www.fesliyanstudios.com.wav");
	sf::Sound disk_sound;
	disk_sound.setBuffer(buffer);

	// music
	sf::Music music;
	music.openFromFile("audio/2020-04-24_-_Arcade_Kid_-_FesliyanStudios.com_-_David_Renda.wav");
	music.setLoop(true);
	music.play();

	sf::RenderWindow window(sf::VideoMode(800, 800), "Tower of Hanoi");
	window.setFramerateLimit(60);


	sf::Vector2u size = window.getSize();
	unsigned int win_width = size.x;
	unsigned int win_height = size.y;

	// the background sprite
	Background bg{ win_width,win_height };

	// the tower 
	TowerOfHanoiGraphic<Disk> t{1,13, win_width,win_height };
	
	sf::Event event;


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::EventType::KeyPressed:
				// reset all disk colors
				t.resetAllTopDiskColor();
				if (event.key.code == sf::Keyboard::A) {
					t._keys_pressed.push_back("a");
					if (t._keys_pressed.size() == 1) {
						t.changeTopDiskColor(0,sf::Color::Red);
					}
					t.printKeyVec();
				}
				else if (event.key.code == sf::Keyboard::S) {
					t._keys_pressed.push_back("s");
					if (t._keys_pressed.size() == 1) {
						t.changeTopDiskColor(1,sf::Color::Red);
					}
					t.printKeyVec();
				}
				else if (event.key.code == sf::Keyboard::D) {
					t._keys_pressed.push_back("d");
					if (t._keys_pressed.size() == 1) {
						t.changeTopDiskColor(2,sf::Color::Red);
					}
					t.printKeyVec();
				}

				if (t.isPattern("a", "s")) {
					if (t.canMove(0, 1)) {
						// change color back
						t.changeTopDiskColor(0,sf::Color::Blue);
						t.moveDisk(0, 1);
						// play sound
						disk_sound.play();
						// reset keys
						t.resetKeys();
					}
				}
				else if (t.isPattern("a", "d")) {
					if (t.canMove(0, 2)) {
						t.changeTopDiskColor(0,sf::Color::Blue);
						t.moveDisk(0, 2);
						disk_sound.play();
						t.resetKeys();
					}
				}
				else if (t.isPattern("s", "a")) {
					if (t.canMove(1, 0)) {
						t.changeTopDiskColor(1,sf::Color::Blue);
						t.moveDisk(1, 0);
						disk_sound.play();
						t.resetKeys();
					}
				}
				else if (t.isPattern("s", "d")) {
					if (t.canMove(1,2)) {
						t.changeTopDiskColor(1,sf::Color::Blue);
						t.moveDisk(1,2);
						disk_sound.play();
						t.resetKeys();
					}
				}
				else if (t.isPattern("d", "a")) {
					if (t.canMove(2,0)) {
						t.changeTopDiskColor(2,sf::Color::Blue);
						t.moveDisk(2,0);
						disk_sound.play();
						t.resetKeys();
					}
				}
				else if (t.isPattern("d", "s")) {
					if (t.canMove(2,1)) {
						t.changeTopDiskColor(2,sf::Color::Blue);
						t.moveDisk(2,1);
						disk_sound.play();
						t.resetKeys();
					}
				}
				else if (event.key.code == sf::Keyboard::R) {
					t.resetDisks();
				}
				else if (event.key.code == sf::Keyboard::V) {
					t.sortDisks();
				}
				else if (event.key.code == sf::Keyboard::Escape) {
					t.resetKeys();
				}
				else if (event.key.code == sf::Keyboard::Q) {
					// quit
					window.close();
				}



			break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		// clear keys if too large
		if (t.keySizeBig()) {
			t.resetKeys();
		}

		// clear window
		window.clear();


		// draw background
		window.draw(bg._rect);
		window.draw(bg._text);

		// draw moves
		window.draw(t._text);

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
		

