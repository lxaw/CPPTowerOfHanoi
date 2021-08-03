#include <iostream>

#include "Sprites.h"

// Peg constructor
Peg::Peg(unsigned int peg_number,unsigned int win_w, unsigned int win_h) {
	_peg_number = peg_number;

	_width = 20;
	_height = 500;
	_y = 50;
	_color = sf::Color{ 255,0,0,255 };

	// calculate margin
	_margin = (win_w - (3*_width)) / 4;

	// calculate x
	_x = (peg_number + 1) * (_margin)+(peg_number * _width);

	// create the rects
	_rect = sf::RectangleShape(sf::Vector2f(_width, _height));
	// set position
	_rect.setPosition(_x, _y);
	// color
	_rect.setFillColor(_color);
}

