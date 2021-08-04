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
	this->_y = 50;
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

// disk constructor
Disk::Disk(int diskID,sf::Color color,unsigned int pegX, int level,int max_level,unsigned int win_w,unsigned int win_h) {
	_diskID = diskID;
	_win_w = win_w;
	_win_h = win_h;
	_max_level = max_level;

	this->_width = (diskID +1) * 20;
	this->_height = 20;
	changePos(pegX, level);

	this->_color = color;
	// create the rects
	this->_rect = sf::RectangleShape(sf::Vector2f(_width, _height));
	// set position
	this->_rect.setPosition(_x, _y);
	// color
	this->_rect.setFillColor(_color);
}

void Disk::changePos(unsigned int pegX, int level) {
	unsigned int new_x = pegX - _width/2 + _height/2; 
	unsigned int new_y = (unsigned int)level;

	int level_adjusted = (std::abs(level - _max_level)+1);
	
	new_y = level_adjusted * (_win_h * 5/7) / _max_level;


	this->_x = new_x;
	this->_y = new_y;
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



