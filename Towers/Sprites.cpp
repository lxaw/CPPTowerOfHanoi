#include <iostream>
#include <cmath>

#include "Sprites.h"

// background color
Background::Background(unsigned int win_w, unsigned int win_h) {
	this->_width = win_w;
	this->_height = win_h;

	this->_color = sf::Color{ 234,234,189 };
	this->_x = 0;
	this->_y = 0;


	// fonts
	_font.loadFromFile("fonts/8bitOperatorPlus8-Regular.ttf");
	_text.setFont(_font);
	_text.setString("\"a\": left, \"s\": middle, \"r\": right \"esc\" reset key press\n\"q\" quit \"v\" sort");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::Black);

	this->_rect = sf::RectangleShape(sf::Vector2f(_width, _height));
	this->_rect.setPosition(_x, _y);
	this->_rect.setFillColor(_color);
}

// Peg default const
Peg::Peg() {
	_peg_number = 0;
	_margin = 0;
}
// Peg constructor
Peg::Peg(unsigned int peg_number,unsigned int win_w, unsigned int win_h) {
	_peg_number = peg_number;

	this->_width = 20;
	this->_height = 500;
	this->_y = 220;
	this->_color = sf::Color{ 156,100,16,255 };

	// calculate margin
	_margin = (win_w - (3*_width)) / 4;

	// calculate x
	this->_x = (peg_number + 1) * (_margin)+(peg_number * _width);

	// create the rects
	this->_rect = sf::RectangleShape(sf::Vector2f(_width, _height));
	// set position
	this->_rect.setPosition(_x, _y);
	// color
	this->_rect.setFillColor(_color);
}

// move disks
void Disk::changePos(Peg peg, int level) {
	this->_level = level;

	unsigned int new_x = peg._x - _width/2 + _height/2; 
	
	unsigned int new_y = (_win_h - 100) - (level*this->_height);


	this->_x = new_x;
	this->_y = new_y;

	// set position
	this->_rect.setPosition(_x, _y);
}



// disk constructor
Disk::Disk(int diskID,sf::Color color,Peg peg, int level,unsigned int win_w,unsigned int win_h) {
	_diskID = diskID;
	_win_w = win_w;
	_win_h = win_h;


	this->_width = (diskID +1) * 20;
	this->_height = 20;
	this->_level = _level;


	this->_color = color;
	// create the rects
	this->_rect = sf::RectangleShape(sf::Vector2f(_width, _height));
	// color
	this->_rect.setFillColor(_color);

	// set position
	this->changePos(peg, level);
}
bool Disk::operator < (Disk const& aDisk) {
	if (_diskID < aDisk._diskID) {
		return true;
	}
	else {
		return false;
	}
}
bool Disk::operator > (Disk const& aDisk) {
	if (_diskID > aDisk._diskID) {
		return true;
	}
	else {
		return false;
	}
}



