#pragma once

#include "SFML/Graphics.hpp"

#include "Stack.h"

class Block
{
public:
	unsigned int _width;
	unsigned int _height;
	unsigned int _x;
	unsigned int _y;

	// sfml stuff
	sf::RectangleShape _rect;
	sf::Color _color;

	// for positioning
};

class Peg: public Block
{
public:

	Peg(unsigned int peg_number, unsigned int win_w, unsigned int win_h);

	unsigned int _peg_number;
	unsigned int _margin;

};

class Disk :public Block 
{
};

